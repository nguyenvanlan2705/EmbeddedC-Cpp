#include <main.h>

#define I2C_SCL_SPEED_SM     100000
#define I2C_SCL_SPEED_FM4K   400000
#define I2C_SCL_SPEED_FM2K   200000

#define I2C_ACK_ENABLE          1
#define I2C_ACK_DISABLE         0

#define I2C_FM_DUTY_2           0
#define I2C_FM_DUTY_19_6        1

#define I2C_FLAG_TXE            (1<<7)
#define I2C_FLAG_RXNE           (1<<6)
#define I2C_FLAG_SB             (1<<0)
#define I2C_FLAG_ADDR           (1<<1)
#define I2C_FLAG_BTF            (1<<2)
uint16_t AHB_PreScaler[8]={2,4,8,16,64,128,256,512};
uint8_t AHB1_PreScaler[4]={2,4,8,16};
typedef struct
{
  uint8_t I2C_Mode;
  uint32_t I2C_SCLSpeed;
  uint8_t I2C_SlaveAddr;
  uint8_t I2C_ACKControl;
  uint16_t I2C_FMDutyCycle;
}I2C_Config;

typedef struct
{
  I2C_TypeDef *pI2Cx;
  I2C_Config  I2Cconfig;
}I2C_Handle;


uint32_t RCC_GetPLLOutputClock()
{
  return 0;
}

uint32_t RCC_GetPCLK1Value(void)
{
  uint32_t pclk1=0, SystemClk;
  uint8_t clksrc,temp,ahbp,ahbp1;
  
  //Choose source clock: HSI or HSE.
  clksrc = (RCC->CFGR >>2) & 0x3;
  
  if(clksrc==0)
  {
    SystemClk = 16000000;
  }
  else if(clksrc ==1)
  {
    SystemClk = 8000000;
  }
  else if(clksrc ==2) 
  {
    SystemClk = RCC_GetPLLOutputClock();
  }
  
  //AHB clock prescaler 
  temp = (RCC->CFGR >>4) & 0xF;
  
  if(temp<8)
  {
    ahbp =1;
  }
  else
  {
    ahbp= AHB_PreScaler[temp-8];
  }
  
  //PRE1 APB1 clock prescaler 
  temp = ((RCC->CFGR >>10) & 0x07);
  if(temp<4)
  {
    ahbp1 =1;
  }
  else
  {
    ahbp1= AHB1_PreScaler[temp-4];
  }
  
  pclk1 = (SystemClk / ahbp) / ahbp1;
  
  return pclk1;
}


void I2C_Init(I2C_Handle *pI2C_Handle)
{
  uint32_t temp=0;
  //ack controll bit
  temp |= pI2C_Handle->I2Cconfig.I2C_ACKControl <<10;
  //config the FREQ field of CR2
  
  temp=0;
  temp= RCC_GetPCLK1Value()/1000000;
  pI2C_Handle->pI2Cx->CR2 = (temp & 0x3F);
  
  //program the device address
  temp |= pI2C_Handle->I2Cconfig.I2C_SlaveAddr << 1;
  temp |= (1<<14);
  pI2C_Handle->pI2Cx->OAR1 = temp;
  
  //CCR caculation
  uint16_t ccrValue=0;
  temp=0;
  if(pI2C_Handle->I2Cconfig.I2C_SCLSpeed <= I2C_SCL_SPEED_SM)
  {
    //Standard mode
    ccrValue = RCC_GetPCLK1Value() / (2*pI2C_Handle->I2Cconfig.I2C_SCLSpeed);
    temp |=ccrValue & 0xFFF;
  }
  else
  {
    //Fast mode
    temp |= (1<<15);
    temp |= (pI2C_Handle->I2Cconfig.I2C_FMDutyCycle <<14);
    if(pI2C_Handle->I2Cconfig.I2C_FMDutyCycle == I2C_FM_DUTY_2)
    {
      ccrValue = RCC_GetPCLK1Value() / (3*pI2C_Handle->I2Cconfig.I2C_SCLSpeed);
    }
    else if(pI2C_Handle->I2Cconfig.I2C_FMDutyCycle == I2C_FM_DUTY_19_6)
    {
      ccrValue = RCC_GetPCLK1Value() / (25*pI2C_Handle->I2Cconfig.I2C_SCLSpeed);
    }
    temp |=ccrValue & 0xFFF;
  }
  pI2C_Handle->pI2Cx->CCR = temp;
  //config the trise 
  if(pI2C_Handle->I2Cconfig.I2C_SCLSpeed <= I2C_SCL_SPEED_SM)
  {
    //config the trise in std mode
    temp = ((RCC_GetPCLK1Value() / 1000000U) +1) ;
  }
  else 
  {
    //config the trise in fast mode
    temp = ((RCC_GetPCLK1Value() *300)/1000000U)+1;
  }
  pI2C_Handle->pI2Cx->TRISE = (temp &0x3F);
}

static void I2C_GenarateStartCondition(I2C_TypeDef *pI2Cx)
{
  pI2Cx->CR1|= (1<<8);
} 
static void I2C_GenarateStopCondition(I2C_TypeDef *pI2Cx)
{
  pI2Cx->CR1|= (1<<9);
}
static void I2C_ExecuteAddressPhaseWrite(I2C_TypeDef *pI2Cx, uint8_t slaveAddr)
{
  slaveAddr = slaveAddr << 1 ; 
  slaveAddr &= ~(1) ; 
  pI2Cx->DR = slaveAddr;
}
static void I2C_ExecuteAddressPhaseRead(I2C_TypeDef *pI2Cx, uint8_t slaveAddr)
{
  slaveAddr = slaveAddr << 1 ; 
  slaveAddr |= (1) ; 
  pI2Cx->DR = slaveAddr;
}
static void I2C_ClearADDRFlag(I2C_TypeDef *pI2Cx)
{
  uint32_t dummyRead = pI2Cx->SR1;
           dummyRead = pI2Cx->SR2;
  (void)dummyRead;
}
uint8_t I2C_GetFlagStatus(I2C_TypeDef *pI2Cx, uint32_t flagName)
{
  if(pI2Cx->SR1 & flagName)
  {
    return 1;
  }
  return 0;
}

void I2C_MasterSendData(I2C_Handle *pI2CHandle, uint8_t *txBuffer, uint32_t len, uint8_t slaveAddr)
{
  //1. Genarate Start condition
   I2C_GenarateStartCondition(pI2CHandle->pI2Cx);
   //2. confirm tha the Start genaration is completed by checking the SB flag in the SR1
   while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_SB));
   //3. Send the address of the slave with R/W bit to W(0)
   I2C_ExecuteAddressPhaseWrite(pI2CHandle->pI2Cx, slaveAddr);
   //4. Confirm that address phase is completed by checking the ADDR flag in SR1
   while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_ADDR));
   //5. Clear the ADDR flag according to ít software sequence
   //Note: until ADDR is cleared SCL will be stretched (pulled to low)
   I2C_ClearADDRFlag(pI2CHandle->pI2Cx);
   //6. Send data until Len =0
   while(len>0)
   {
     while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_TXE));
     pI2CHandle->pI2Cx->DR = *txBuffer;
     txBuffer++;
     len --;
   }
   
   //7. When len becomes 0 wait for TXE=1 and BTF =1 before generating STOP condition
   //Note: TXE=1, BTF =1, means that both SR and DR are empty and next transmission should be begin
   // When BTF=1 SCL will be stretched (pull to low)
   while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_TXE));
   while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_BTF));
   
   
   //8. Genarate STOP condition and master need not to wait for the completion of stop condition 
   // Note: Generating STOP, automatically clears the BTF
   I2C_GenarateStopCondition(pI2CHandle->pI2Cx);
}

void I2C_ManageACK(I2C_TypeDef *pI2Cx, uint8_t role)
{
  if(role ==I2C_ACK_ENABLE)
  {
    pI2Cx->CR1 |= (1<<10);
  }
  else
  {
    pI2Cx->CR1 &= ~(1<<10);
  }
}
void I2C_MasterReceiveData(I2C_Handle *pI2CHandle, uint8_t *rxBuffer, uint32_t len, uint8_t slaveAddr)
{
  //1. Generate the Start conditon
  I2C_GenarateStartCondition(pI2CHandle->pI2Cx);
  //2. confirm tha the Start genaration is completed by checking the SB flag in the SR1
   while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_SB));
   //3. Send the address of the slave with R/W bit to W(0)
   I2C_ExecuteAddressPhaseRead(pI2CHandle->pI2Cx, slaveAddr);
   //4. Confirm that address phase is completed by checking the ADDR flag in SR1
   while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_ADDR));
   
   //procedure only 1 byte
   if(len ==1)
   {
     //Disable ACK
     I2C_ManageACK(pI2CHandle->pI2Cx, I2C_ACK_DISABLE);
     //generate STOP condition
     I2C_GenarateStopCondition(pI2CHandle->pI2Cx);
     //Clear ADDR flag
     I2C_ClearADDRFlag(pI2CHandle->pI2Cx);
     //wait until RXNE becomes 1
     while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_RXNE));
     //read data in to buffer
     *rxBuffer = pI2CHandle->pI2Cx->DR;
      return; 
   }
   if(len>1)
   {
     //Clear ADDR flag
     I2C_ClearADDRFlag(pI2CHandle->pI2Cx);
     //Read the data until Len becomes 0
     for (uint32_t i=len; i>0; i--)
     {
       //wait until RXNE becomes 1
       while(!I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_RXNE));
       if(i==2) //two last byte
       {
         //Disable ACK
         I2C_ManageACK(pI2CHandle->pI2Cx, I2C_ACK_DISABLE);
         //generate STOP condition
         I2C_GenarateStopCondition(pI2CHandle->pI2Cx);
         
       }
       
       //read data from DR into buffer
       *rxBuffer = pI2CHandle->pI2Cx->DR;
       //increment the buffer address
       *rxBuffer++;
     }
   }
   //re-enable ACK
   if(pI2CHandle->I2Cconfig.I2C_ACKControl == I2C_ACK_ENABLE)
   {
     I2C_ManageACK(pI2CHandle->pI2Cx, I2C_ACK_ENABLE);
   }
}

int main()
{
}