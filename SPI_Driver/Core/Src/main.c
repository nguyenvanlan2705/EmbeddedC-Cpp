#include "main.h"
#include <string.h>
#include "stddef.h"


#define __weak __attribute__((weak))
typedef struct{
  volatile uint32_t CR1;       
  volatile uint32_t CR2;        
  volatile uint32_t SR;         
  volatile uint32_t DR;         
  volatile uint32_t CRCPR;      
  volatile uint32_t RXCRCR;     
  volatile uint32_t TXCRCR;     
  volatile uint32_t I2SCFGR;    
  volatile uint32_t I2SPR;     
}SPI_Type;
#define SPI1_REG ((SPI_Type*)0x40013000U)
#define SPI2_REG ((SPI_Type*)0x40003800U)
#define SPI3_REG ((SPI_Type*)0x40003C00U)


typedef struct{
volatile uint32_t GPIO_MODER;
volatile uint32_t GPIO_OTYPER;
volatile uint32_t GPIO_OSPEEDR;
volatile uint32_t GPIO_PUPDR;
volatile uint32_t GPIO_IDR;
volatile uint32_t GPIO_ODR;
volatile uint32_t GPIO_BSRR;
volatile uint32_t GPIO_LCKR;
volatile uint32_t GPIO_AFR[2];
}GPIO_Type;

#define GPIOA_REG ((GPIO_Type*)0x40020000)
#define GPIOB_REG ((GPIO_Type*)0x40020400)
#define GPIOC_REG ((GPIO_Type*)0x40020800)
#define GPIOD_REG ((GPIO_Type*)0X40020C00)

typedef struct {
volatile uint32_t RCC_CR;
volatile uint32_t RCC_PLLCFGR;
volatile uint32_t RCC_CFGR;
volatile uint32_t RCC_CIR;
volatile uint32_t RCC_AHB1RSTR;
volatile uint32_t RCC_AHB2RSTR;
volatile uint32_t RCC_AHB3RSTR;
volatile uint32_t Reserved1;
volatile uint32_t RCC_APB1RSTR;
volatile uint32_t RCC_APB2RSTR;
volatile uint32_t Reserved2[2];
volatile uint32_t RCC_AHB1ENR;
volatile uint32_t RCC_AHB2ENR;
volatile uint32_t RCC_AHB3ENR;
volatile uint32_t Reserved3;
volatile uint32_t RCC_APB1ENR;
volatile uint32_t RCC_APB2ENR;
}RCC_Type;
#define RCC_REG ((RCC_Type*)0x40023800)

typedef struct{
  volatile uint32_t EXTI_IMR;
  volatile uint32_t EXTI_EMR;
  volatile uint32_t EXTI_RTSR;
  volatile uint32_t EXTI_FTSR;
  volatile uint32_t EXTI_SWIER;
  volatile uint32_t EXTI_PR;
}ExIrq_Def;
#define EXTI_REG ((ExIrq_Def*)0x40013C00)

typedef struct
{
  volatile uint32_t MEMRMP;                           
  volatile uint32_t PMC;         
  volatile uint32_t EXTICR[4];    
  uint32_t          RESERVED[2];                                             
  volatile uint32_t CMPCR;        
}SYSCFG_Def;
#define Sys_REG ((SYSCFG_Def*)0x40013800)


typedef struct{
	uint8_t GPIO_pinNum;
	uint8_t GPIO_pinMode;
	uint8_t GPIO_pinSpeed;
	uint8_t GPIO_pinPuPdControl;
	uint8_t GPIO_OPtype;
	uint8_t GPIO_pinAltFuncMode;
}GPIO_PinConfig;

typedef  struct{
  GPIO_Type             *pGPIOx;
  GPIO_PinConfig        GPIO_PinConfig;
}GPIO_Handle;


typedef struct{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_SclkSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPOL;
    uint8_t SPI_CPHA;
    uint8_t SPI_SSM;  
}SPI_Config;

typedef struct
{
    SPI_Type *pSPIx;
    SPI_Config  SPIConfig;
    uint8_t *pTxBuffer;
    uint8_t *pRxBuffer;
    uint32_t TxLen;
    uint32_t RxLen;
    uint8_t TxState;
    uint8_t RxState;
}SPI_Handle;


#define GPIOA_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<0))
#define GPIOB_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<1))
#define GPIOC_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<2))
#define GPIOD_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<3))

#define SPI1_CLK_EN()   (RCC_REG->RCC_APB2ENR|=(1<<12))
#define SPI2_CLK_EN()   (RCC_REG->RCC_APB1ENR|=(1<<14))
#define SPI3_CLK_EN()   (RCC_REG->RCC_APB1ENR|=(1<<15))

#define SYS_CLK_EN()    (RCC_REG->RCC_APB2ENR|=(1<<14))

#define GPIO_BASEADDR_TO_CODE(x)         ((x==GPIOA_REG)? 0:\
                                          (x==GPIOB_REG)? 1:\
                                          (x==GPIOC_REG)? 2:\
                                          (x==GPIOD_REG)? 3:0)
  
                                          
#define ENABLE                          1
#define SET                             1
#define RESET                           0
#define FLAG_SET                        1
#define FLAG_RESET                      0

#define SPI_TXE_FLAG                    (1<<1)
#define SPI_RNXE_FLAG                   (1<<0)
#define SPI_BUSY_FLAG                   (1<<7)


#define SPI_READY       0
#define SPI_BUSY_IN_RX  1
#define SPI_BUSY_IN_TX  2

#define  SPI_EVENT_TX_CMPLT             1
#define  SPI_EVENT_RX_CMPLT             2
#define  SPI_EVENT_OVR_ERR              3
#define  SPI_EVENT_CRC_ERR              4

//define NVIC ISERx Register of ARM Cortex Mx

#define  NO_PR_BITS_IMPLEMENTED         4

#define NVIC_IRQ_PRI0           0
#define NVIC_IRQ_PRI15          15

#define NVIC_ISER0                      ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1                      ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2                      ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3                      ((volatile uint32_t*)0xE000E10C)
#define NVIC_PR_BASEADDR                ((volatile uint32_t*)0xE000E400) 
#define IRQ_EXTI0                       6
#define IRQ_EXTI1                       7
#define IRQ_EXTI2                       8
#define IRQ_EXTI3                       9
#define IRQ_EXTI4                       10
#define IRQ_EXTI9_5                     23
#define IRQ_EXTI15_10                   40


#define GPIO_PIN_NO_0  			                0
#define GPIO_PIN_NO_1  			                1
#define GPIO_PIN_NO_2  			                2
#define GPIO_PIN_NO_3 			                3
#define GPIO_PIN_NO_4  			                4
#define GPIO_PIN_NO_5  			                5
#define GPIO_PIN_NO_6	 		                6
#define GPIO_PIN_NO_7  		        	        7
#define GPIO_PIN_NO_8  		        	        8
#define GPIO_PIN_NO_9  		        	        9
#define GPIO_PIN_NO_10                                  10
#define GPIO_PIN_NO_11  			        11
#define GPIO_PIN_NO_12  			        12
#define GPIO_PIN_NO_13  			        13
#define GPIO_PIN_NO_14  			        14
#define GPIO_PIN_NO_15  			        15

/*
 * GPIO PIN MODES
 */
#define GPIO_MOD_IN 			0
#define GPIO_MOD_OUT 			1
#define GPIO_MOD_ALTFN 		        2
#define GPIO_MOD_ANALOG 		3
#define GPIO_MOD_IT_FT 		        4
#define GPIO_MOD_IT_RT 		        5
#define GPIO_MOD_IT_RFT 		6

/*
 * GPIO OUTPUT TYPE
 */
#define GPIO_OPTYPE_PP 			0
#define GPIO_OPTYPE_OD 			1

/*
 * GPIO SPEED
 */
#define GPIO_SPEEDLOW 				0
#define GPIO_SPEEDMEDIUM 			1
#define GPIO_SPEEDFAST 			        2
#define GPIO_SPEEDHIGH 			        3

/*
 * GPIO PULLLUP / PULLDOW SETTINGS
 */
#define GPIO_NO_PUPD 			        0
#define GPIO_PU 				1
#define GPIO_PD 				2

//SPI  macro
#define SPI_Master               1
#define SPI_Slave                0

#define SPI_FullDuplex           1      
#define SPI_HalfDuplex           2        
#define SPI_Simplex_RxOnly       3

#define SPI_CLK_DIV2            0
#define SPI_CLK_DIV4            1
#define SPI_CLK_DIV8            2      
#define SPI_CLK_DIV16           3
#define SPI_CLK_DIV32           4       
#define SPI_CLK_DIV64           5
#define SPI_CLK_DIV128          6
#define SPI_CLK_DIV256          7

#define SPI_DFF_8Bits           0
#define SPI_DFF_16Bits          1

#define SPI_CPOL_LOW            0
#define SPI_CPOL_HIGH           1

#define SPI_CPHA_LOW            0
#define SPI_CPHA_HIGH           1

#define SPI_SSW_EN              1
#define SPI_SSW_DI              0



/*
******************************************GPIO API***********************************************
*/
void GPIO_Init(GPIO_Handle *pGPIOHandle);
void GPIO_PeriClkControl(GPIO_Type *pGPIOx, uint8_t EnorDi);
/*
****************************************SPI API*************************
*/
void SPI_Init(SPI_Handle *pSPI_Handle);
void SPI_PeriClkControl(SPI_Type *pSPIx, uint8_t EnorDi);
void SPI_SendData(SPI_Type *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_Type *pSPIx, uint8_t *pRxBuffer, uint32_t Len);


uint8_t SPI_SendDataIT(SPI_Handle *pSPIHandle, uint8_t *pTxBuffer, uint32_t Len);
uint8_t SPI_ReceiveDataIT(SPI_Handle *pSPIHandle, uint8_t *pRxBuffer, uint32_t Len);
void SPI_IRQConfig(uint8_t IRQNumber, uint8_t role);
void SPI_IQRPriorityConfig(uint8_t IRQNumber,uint8_t IQRPriority);
void SPI_Handling(SPI_Handle *pHandle);

static void spi_txe_irq_handle(SPI_Handle *pSPIHandle);
static void spi_rxne_irq_handle(SPI_Handle *pSPIHandle);
static void spi_ovr_err_irq_handle(SPI_Handle *pSPIHandle);


static void GPIO_PeriClkControl(GPIO_Type *pGPIOx, uint8_t EnorDi)
{
if(EnorDi==ENABLE)
{
  if(pGPIOx==GPIOA_REG)
	GPIOA_CLK_EN();
  else if(pGPIOx==GPIOB_REG)
	GPIOB_CLK_EN();
  else if(pGPIOx==GPIOC_REG)
          GPIOC_CLK_EN();
  else if(pGPIOx==GPIOD_REG)
          GPIOD_CLK_EN();
  }
  else
  {
  }
}
void GPIO_Init(GPIO_Handle *pGPIOHandle){
  uint32_t temp=0;
  GPIO_PeriClkControl(pGPIOHandle->pGPIOx, ENABLE);
  
//1. mode of gpio
  if(pGPIOHandle->GPIO_PinConfig.GPIO_pinMode <= GPIO_MOD_ANALOG)
  {
    temp= pGPIOHandle->GPIO_PinConfig.GPIO_pinMode << (2* pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
    pGPIOHandle->pGPIOx->GPIO_MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_pinNum); //clear
    pGPIOHandle->pGPIOx->GPIO_MODER |= temp; //setting
    temp=0;
  }
  else
  {
		// interrupt mode
    if(pGPIOHandle->GPIO_PinConfig.GPIO_pinMode == GPIO_MOD_IT_FT) //IRQ Falling edge
    {
      //1. config FTSR
      EXTI_REG->EXTI_FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
      EXTI_REG->EXTI_RTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
    }
    else if(pGPIOHandle->GPIO_PinConfig.GPIO_pinMode == GPIO_MOD_IT_RT) //IRQ Rising edge
    {
      EXTI_REG->EXTI_RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
      EXTI_REG->EXTI_FTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
    }
    else if(pGPIOHandle->GPIO_PinConfig.GPIO_pinMode == GPIO_MOD_IT_RFT) //IRQ Falling edge
    {
      EXTI_REG->EXTI_RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
      EXTI_REG->EXTI_FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
    }
    //2. Config GPIO port selection in SYSCFG_EXTICR
    uint8_t temp1= pGPIOHandle->GPIO_PinConfig.GPIO_pinNum/4;
    uint8_t temp2= pGPIOHandle->GPIO_PinConfig.GPIO_pinNum%4;
    uint8_t portCode =GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
    SYS_CLK_EN();
    Sys_REG->EXTICR[temp1] = portCode <<(temp2*4);
    //3. Enalble the EXTI interrupt delivering using IMR Reg
    EXTI_REG->EXTI_IMR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
  }
  //2. speed
  temp= pGPIOHandle->GPIO_PinConfig.GPIO_pinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
  pGPIOHandle->pGPIOx->GPIO_OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_pinNum); //clear
  pGPIOHandle->pGPIOx->GPIO_OSPEEDR |= temp;
  temp=0;

//3. pupd settings
  temp= pGPIOHandle->GPIO_PinConfig.GPIO_pinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
  pGPIOHandle->pGPIOx->GPIO_PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_pinNum); //clear
  pGPIOHandle->pGPIOx->GPIO_PUPDR |= temp;
  temp=0;

//4. otype
  temp= pGPIOHandle->GPIO_PinConfig.GPIO_OPtype << (pGPIOHandle->GPIO_PinConfig.GPIO_pinNum);
  pGPIOHandle->pGPIOx->GPIO_ODR &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_pinNum); //clear
  pGPIOHandle->pGPIOx->GPIO_ODR |= temp;
  temp=0;

//5. alt functionality
if(pGPIOHandle->GPIO_PinConfig.GPIO_pinMode == GPIO_MOD_ALTFN)
{
  uint32_t temp1, temp2;
  temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_pinNum /8;
  temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_pinNum %8;
  pGPIOHandle->pGPIOx->GPIO_AFR[temp1] &= ~(0xF <<(4* temp2));
  pGPIOHandle->pGPIOx->GPIO_AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_pinAltFuncMode<<(4* temp2));
}
}


void SPI2_Init();
void SPI_PeriClkControl(SPI_Type *pSPIx, uint8_t EnorDi);
void SPI_SendData(SPI_Type *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_SSIConfig(SPI_Type *pSPIx, uint8_t role);

void SPI_ClearOVRFlag(SPI_Type *pSPIx);
void SPI_CloseTransmission(SPI_Handle *pSPIHandle);
void SPI_CloseReception(SPI_Handle *pSPIHandle);
void SPI_ApplicationEventCallback(SPI_Handle *pSPIHandle, uint8_t AppEv);


void SPI_PeriClkControl(SPI_Type *pSPIx, uint8_t EnorDi)
{
  if(EnorDi==ENABLE){
      if(pSPIx==SPI1_REG)
        SPI1_CLK_EN();
      else if(pSPIx==SPI2_REG)
        SPI2_CLK_EN();
      else if(pSPIx==SPI3_REG)
        SPI3_CLK_EN();
  } 
}

void SPI_Init(SPI_Handle *pSPI_Handle)
{
    // Config the SPI_CR1
  uint32_t temp=0;
  SPI_PeriClkControl(pSPI_Handle->pSPIx, ENABLE);
    // 1. Config device mode
   temp |= pSPI_Handle->SPIConfig.SPI_DeviceMode <<2;
   if(pSPI_Handle->SPIConfig.SPI_BusConfig == SPI_FullDuplex)
   {
     //bidi mode should be cleared
     temp &=~(1<<15);
   }
   else if(pSPI_Handle->SPIConfig.SPI_BusConfig == SPI_HalfDuplex)
   {
     //bidi mode should be set
     temp |= (1<<15);
   }
   else if(pSPI_Handle->SPIConfig.SPI_BusConfig == SPI_Simplex_RxOnly)
   {
     //bidi mode should be cleared
     temp &=~(1<<15);
     //RXONLY bit must be set
     temp |= (1<<10);
   }
   
   //2. Config the SPI serial clock speed (baud rate)
   temp |= pSPI_Handle->SPIConfig.SPI_SclkSpeed <<3;
   //3. Config data frame format DFF
   temp |= pSPI_Handle->SPIConfig.SPI_DFF <<11;
   //4. Config the CPOL
   temp |= pSPI_Handle->SPIConfig.SPI_CPOL <<1;
   //5. Config the CPHA
   temp |= pSPI_Handle->SPIConfig.SPI_CPHA <<0;
  
   
   pSPI_Handle->pSPIx->CR1 = temp;
}

uint8_t SPI_GetFlagStatus(SPI_Type *pSPIx, uint32_t FlagName)
{
  if(pSPIx->SR & FlagName)
  {
    return FLAG_SET;
  }
  return FLAG_RESET;
}

//this is blocking call
void SPI_SendData(SPI_Type *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
  while (Len>0)
  {
    //1. Wait until TXE is set
    while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);
    //2. Check the DFF bit in CR1
      if(pSPIx->CR1 &(1<<11))
      {
        //frame 16 bit 
        //1. load the data into the DR
        pSPIx->DR = *((uint16_t*)pTxBuffer);
        Len--;
        Len--;
        (uint16_t*)pTxBuffer++;
      }
      else
      {
        pSPIx->DR = *((uint8_t*)pTxBuffer);
        Len--;
        pTxBuffer++;
      }
  }
}


__weak  void SPI_ApplicationEventCallback(SPI_Handle *pSPIHandle, uint8_t AppEv)
{
  //This is a weak implementation the use application may override this function
}
void SPI_CloseTransmission(SPI_Handle *pSPIHandle)
{
  //TxLne is 0 -> close the spi transmission adn inform the application that TX is over
    pSPIHandle->pSPIx->CR2 &=~(1<<7); //prevent interrupt from setting up  of TXE flag
    pSPIHandle->pTxBuffer =NULL;
    pSPIHandle->TxLen =0;
    pSPIHandle->TxState= SPI_READY;
}

void SPI_CloseReception(SPI_Handle *pSPIHandle)
{
    //Reception is complete
    //letss turn off the rxneie interrupt
    pSPIHandle->pSPIx->CR2 &=~(1<<6); //prevent interrupt from setting up  of  flag
    pSPIHandle->pRxBuffer =NULL;
    pSPIHandle->RxLen =0;
    pSPIHandle->RxState= SPI_READY;
}

void SPI_ClearOVRFlag(SPI_Type *pSPIx)
{
  uint8_t temp;
  temp = pSPIx ->DR;
  temp = pSPIx ->SR;
  (void)temp;
}
uint8_t SPI_SendDataIT(SPI_Handle *pSPIHandle, uint8_t *pTxBuffer, uint32_t Len)
{
  uint8_t state = pSPIHandle->TxState;
  if(state != SPI_BUSY_IN_RX)
  {
    //1. Save the Tx buffer address and Len information in some global variables
    pSPIHandle->pTxBuffer =pTxBuffer;
    pSPIHandle->TxLen = Len;
    //2. Mark the SPI state as busy in transmission so that 
    //no other code can take same SPI peripheral until transmission is over
    pSPIHandle->TxState = SPI_BUSY_IN_TX;
    
    //3. Enable the TXEIE control bit to get interrupt whenever TXE flag is set in SR
    pSPIHandle->pSPIx->CR2 |= (1<<7);
  }
  return state;
}

uint8_t SPI_ReceiveDataIT(SPI_Handle *pSPIHandle, uint8_t *pRxBuffer, uint32_t Len)
{
  uint8_t state = pSPIHandle->RxState;
  if(state != SPI_BUSY_IN_TX)
  {
    //1. Save the Tx buffer address and Len information in some global variables
    pSPIHandle->pRxBuffer =pRxBuffer;
    pSPIHandle->RxLen = Len;
    //2. Mark the SPI state as busy in transmission so that 
    //no other code can take same SPI peripheral until transmission is over
    pSPIHandle->RxState = SPI_BUSY_IN_RX;
    
    //3. Enable the TXEIE control bit to get interrupt whenever TXE flag is set in SR
    pSPIHandle->pSPIx->CR2 |= (1<<6);
  }
  return state;
}

void spi_txe_irq_handle(SPI_Handle *pSPIHandle)
{
  if(pSPIHandle->pSPIx->CR1 &(1<<11))
  {
    //frame 16 bit 
    //1. load the data into the DR
     pSPIHandle->pSPIx->DR = *((uint16_t*)pSPIHandle->pTxBuffer);
     pSPIHandle->TxLen--;
     pSPIHandle->TxLen--;
     (uint16_t*)pSPIHandle->pTxBuffer++;
   }
   else
   {
     pSPIHandle->pSPIx->DR = *((uint8_t*)pSPIHandle->pTxBuffer);
     pSPIHandle->TxLen--;
     pSPIHandle->pTxBuffer++;
   }
  
  if(!pSPIHandle->TxLen)
  {
    SPI_CloseTransmission(pSPIHandle);
    SPI_ApplicationEventCallback(pSPIHandle, SPI_EVENT_TX_CMPLT);
  }
}
void spi_rxne_irq_handle(SPI_Handle *pSPIHandle)
{
  if(pSPIHandle->pSPIx->CR1 &(1<<11))
  {
    //frame 16 bit 
    //1. load the data into the DR
     *((uint16_t*)pSPIHandle->pTxBuffer) = (uint16_t)pSPIHandle->pSPIx->DR;
     pSPIHandle->RxLen-=2;
     pSPIHandle->pRxBuffer--;
     pSPIHandle->pRxBuffer--;
   }
   else
   {
     *(pSPIHandle->pTxBuffer) = pSPIHandle->pSPIx->DR;
     pSPIHandle->RxLen--;
     pSPIHandle->pRxBuffer++;
   }
  
  if(!pSPIHandle->RxLen)
  {
    SPI_CloseReception(pSPIHandle);
    SPI_ApplicationEventCallback(pSPIHandle, SPI_EVENT_RX_CMPLT);
  }
}

static void spi_ovr_err_irq_handle(SPI_Handle *pSPIHandle)
{
  uint8_t temp;
  //1. Clear the OVR flag
  if(pSPIHandle->TxState != SPI_BUSY_IN_TX)
  {
    temp = pSPIHandle->pSPIx ->DR;
    temp = pSPIHandle->pSPIx ->SR;
  }
  //2. Inform the application
  (void)temp;
  SPI_ApplicationEventCallback(pSPIHandle, SPI_EVENT_OVR_ERR);
}
void SPI_Handling(SPI_Handle *pHandle)
{
  uint8_t temp1, temp2;
  //First check for TXE
  temp1 = pHandle->pSPIx->SR & (1<<1);
  temp2= pHandle->pSPIx->CR2 & (1<<7);
  
  if(temp1 && temp2 )
  {
    // Handle TXE
    spi_txe_irq_handle();
  }
  
  // check for RXNE
  temp1 = pHandle->pSPIx->SR & (1<<0);
  temp2= pHandle->pSPIx->CR2 & (1<<6);
   if(temp1 && temp2 )
  {
    // Handle RXNE
    spi_rxne_irq_handle();
  }
  
  temp1 = pHandle->pSPIx->SR & (1<<6);
  temp2= pHandle->pSPIx->CR2 & (1<<5);
   if(temp1 && temp2 )
  {
    // Handle OVERUN ERROR
    spi_ovr_err_irq_handle();
  }
}
/*
* PB14 -> SPI2_MISO
* PB15 -> SPI2_MOSI
* PB13 -> SPI2_SCLK
* PB12 -> SPI2_NSS
* ALTF mode 5
*/
void SPI_GPIOInit()
{
  GPIO_Handle   SPIPins;
  SPIPins.pGPIOx= GPIOA_REG;
  SPIPins.GPIO_PinConfig.GPIO_pinMode =GPIO_MOD_ALTFN;
  SPIPins.GPIO_PinConfig.GPIO_pinAltFuncMode= 5;
  SPIPins.GPIO_PinConfig.GPIO_OPtype = GPIO_PU;
  SPIPins.GPIO_PinConfig.GPIO_pinPuPdControl = GPIO_NO_PUPD;
  SPIPins.GPIO_PinConfig.GPIO_pinSpeed= GPIO_SPEEDFAST;
  
  //SCLK
  SPIPins.GPIO_PinConfig.GPIO_pinNum = GPIO_PIN_NO_5;
  GPIO_Init(&SPIPins);
  //MOSI
  SPIPins.GPIO_PinConfig.GPIO_pinNum = GPIO_PIN_NO_7;
  GPIO_Init(&SPIPins);
  //MISO
  SPIPins.GPIO_PinConfig.GPIO_pinNum = GPIO_PIN_NO_6;
  GPIO_Init(&SPIPins);
  //NSS
  SPIPins.GPIO_PinConfig.GPIO_pinNum = GPIO_PIN_NO_9;
  GPIO_Init(&SPIPins);
}
void SPI_PeripheralControl(SPI_Type *pSPIx, uint8_t role)
{
  if(role ==ENABLE)
    pSPIx->CR1 |= (1<<6);
  else
    pSPIx->CR1 &= ~(1<<6);
}
void SPI_SSIConfig(SPI_Type *pSPIx, uint8_t role)
{
  if(role ==ENABLE)
    pSPIx->CR1 |= (1<<8);
  else
    pSPIx->CR1 &= ~(1<<8);
}
void SPI2_Init()
{
  SPI_Handle SPI2Handle;
  
  SPI2Handle.pSPIx = SPI1_REG;
  SPI2Handle.SPIConfig.SPI_BusConfig = SPI_FullDuplex;
  SPI2Handle.SPIConfig.SPI_DeviceMode= SPI_Master;
  SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_CLK_DIV2;
  SPI1_REG->CR1 |= (1<<8) | (1<<9);
  SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8Bits;
  SPI2Handle.SPIConfig.SPI_CPOL =SPI_CPOL_HIGH;
  SPI2Handle.SPIConfig.SPI_CPHA =SPI_CPHA_LOW;
  
  SPI_Init(&SPI2Handle);
}
uint8_t txData[] = "hello world";
int main()
{
  
  SPI_GPIOInit();
  //SPI2_REG->CR1 |= 1<<9;
  //SPI2_REG->CR1 |= 1<<6;
  SPI2_Init();
  SPI_PeripheralControl(SPI1_REG, ENABLE);
  //SPI_SSIConfig(SPI1_REG, ENABLE);
  
  
  while (1)
  {
    SPI_SendData(SPI1_REG, (uint8_t*)txData, 13);
    
  }
  return 0;
}