#include <main.h>

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

static void GPIO_Init();
static void GPIO_PeriClkControl(GPIO_Type *pGPIOx, uint8_t EnorDi);
uint8_t GPIO_ReadPin(GPIO_Type *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadPort(GPIO_Type *pGPIOx);
void GPIO_WritePin(GPIO_Type *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WritePort(GPIO_Type *pGPIOx, uint16_t pinNumber);
void GPIO_TogglePin(GPIO_Type *pGPIOx, uint8_t PinNumber);
void GPIO_TogglePort(GPIO_Type *pGPIOx, uint8_t startPinNumber, uint16_t value);
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t role);
void GPIO_IQRPriorityConfig(uint8_t IRQNumber,uint8_t IQRPriority);
void GPIO_Handling(uint8_t pinNumber);


#define GPIOA_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<0))
#define GPIOB_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<1))
#define GPIOC_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<2))
#define GPIOD_CLK_EN()  (RCC_REG->RCC_AHB1ENR|=(1<<3))
#define SYS_CLK_EN()    (RCC_REG->RCC_APB2ENR|=(1<<14))

#define GPIO_BASEADDR_TO_CODE(x)         ((x==GPIOA_REG)? 0:\
                                          (x==GPIOB_REG)? 1:\
                                          (x==GPIOC_REG)? 2:\
                                          (x==GPIOD_REG)? 3:0)
  
                                          
#define ENABLE                          1
#define SET                             1
#define RESET                           0


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

/*
******************************************GPIO API***********************************************
*/
void GPIO_Init(GPIO_Handle *pGPIOHandle){
  uint32_t temp=0;
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
    else if(pGPIOHandle->GPIO_PinConfig.GPIO_pinMode == GPIO_MOD_IT_RT) //IRQ Falling edge
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
  pGPIOHandle->pGPIOx->GPIO_AFR[temp1] &= (0xF <<(4* temp2));
  pGPIOHandle->pGPIOx->GPIO_AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_pinAltFuncMode<<(4* temp2));
}


}

void GPIO_PeriClkControl(GPIO_Type *pGPIOx, uint8_t EnorDi)
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

uint8_t GPIO_ReadPin(GPIO_Type *pGPIOx, uint8_t pinNumber)
{
  uint8_t value;
  value= (uint8_t)((pGPIOx->GPIO_IDR >> pinNumber) & 0x00000001);
  return value;
}

uint16_t GPIO_ReadPort(GPIO_Type *pGPIOx)
{
  uint16_t value;
  value= (uint16_t)(pGPIOx->GPIO_IDR);
  return value;
}


void GPIO_WritePin(GPIO_Type *pGPIOx, uint8_t pinNumber, uint8_t value)
{
  if(value ==SET)
  {
    pGPIOx->GPIO_ODR |= (1<<pinNumber);
  }
  else if(value ==RESET)
  {
    pGPIOx->GPIO_ODR &= ~(1<<pinNumber);
  }
}

void GPIO_WritePort(GPIO_Type *pGPIOx, uint16_t value)
{
  pGPIOx->GPIO_ODR |= value; 
}

void GPIO_TogglePin(GPIO_Type *pGPIOx, uint8_t PinNumber)
{
  pGPIOx->GPIO_ODR ^= (1<<PinNumber);
}

void GPIO_TogglePort(GPIO_Type *pGPIOx, uint8_t startPinNumber, uint16_t value)
{
  pGPIOx->GPIO_ODR ^= (value<<startPinNumber);
}

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t role)
{
  if(role ==ENABLE)
  {
    if(IRQNumber <=31)
    {
      //program ISER0 Register(NVIC Register) (in PM of stm32 doc )
      *NVIC_ISER0 |= (1<< IRQNumber);
      
    }
    else if(IRQNumber>31 && IRQNumber<64)
    {
      //program ISER1 Register
      *NVIC_ISER1 |= (1<< IRQNumber %32);
    }
    else if(IRQNumber>=64 && IRQNumber<96)
    {
      //program ISER2 Register
      *NVIC_ISER2 |= (1<< IRQNumber %64);
    }
  }
  else
  {
     if(IRQNumber <=31)
    {
      //program ISER0 Register(NVIC Register) (in PM of stm32 doc )
      *NVIC_ISER0 |= (1<< IRQNumber);
      
    }
    else if(IRQNumber>31 && IRQNumber<64)
    {
      //program ISER1 Register
      *NVIC_ISER1 |= (1<< IRQNumber %32);
    }
    else if(IRQNumber>=64 && IRQNumber<96)
    {
      //program ISER2 Register
      *NVIC_ISER2 |= (1<< IRQNumber %64);
    }
  }
}
void GPIO_IQRPriorityConfig(uint8_t IRQNumber, uint8_t IQRPriority)
{
  //1.Find out the ipr register
  uint8_t iprx =                IRQNumber/4;
  uint8_t iprx_section =        IRQNumber%4;
  uint8_t shitfAmount = (8*iprx_section)+ (8-NO_PR_BITS_IMPLEMENTED);
  *(NVIC_PR_BASEADDR+iprx*4) |= (IQRPriority << shitfAmount);
}
void GPIO_Handling(uint8_t pinNumber)
{
  if(EXTI_REG->EXTI_PR &(1<<pinNumber))
  {
    EXTI_REG->EXTI_PR |= (1<<pinNumber);
  }
}
void delay(uint32_t time)
{
  for(uint32_t i=0; i< time ; i++);
}
int main()
{
  GPIO_PeriClkControl(GPIOD_REG, ENABLE);
  GPIO_PeriClkControl(GPIOA_REG, ENABLE);
  
  GPIO_Handle toggleLedD12,toggleLedD13,toggleLedD14,toggleLedD15, buttonExtI;
  
  toggleLedD12.pGPIOx= GPIOD_REG;
  toggleLedD12.GPIO_PinConfig.GPIO_pinNum =GPIO_PIN_NO_12;
  toggleLedD12.GPIO_PinConfig.GPIO_pinMode = GPIO_MOD_OUT;
  toggleLedD12.GPIO_PinConfig.GPIO_pinSpeed = GPIO_SPEEDFAST;
  toggleLedD12.GPIO_PinConfig.GPIO_OPtype = GPIO_OPTYPE_PP;
  toggleLedD12.GPIO_PinConfig.GPIO_pinPuPdControl= GPIO_NO_PUPD;
  
  GPIO_Init(&toggleLedD12);
  
  toggleLedD13.pGPIOx= GPIOD_REG;
  toggleLedD13.GPIO_PinConfig.GPIO_pinNum =GPIO_PIN_NO_13;
  toggleLedD13.GPIO_PinConfig.GPIO_pinMode = GPIO_MOD_OUT;
  toggleLedD13.GPIO_PinConfig.GPIO_pinSpeed = GPIO_SPEEDFAST;
  toggleLedD13.GPIO_PinConfig.GPIO_OPtype = GPIO_OPTYPE_PP;
  toggleLedD13.GPIO_PinConfig.GPIO_pinPuPdControl= GPIO_NO_PUPD;
  
  GPIO_Init(&toggleLedD13);
  
  toggleLedD14.pGPIOx= GPIOD_REG;
  toggleLedD14.GPIO_PinConfig.GPIO_pinNum =GPIO_PIN_NO_14;
  toggleLedD14.GPIO_PinConfig.GPIO_pinMode = GPIO_MOD_OUT;
  toggleLedD14.GPIO_PinConfig.GPIO_pinSpeed = GPIO_SPEEDFAST;
  toggleLedD14.GPIO_PinConfig.GPIO_OPtype = GPIO_OPTYPE_PP;
  toggleLedD14.GPIO_PinConfig.GPIO_pinPuPdControl= GPIO_NO_PUPD;
  
  GPIO_Init(&toggleLedD14);
  
  toggleLedD15.pGPIOx= GPIOD_REG;
  toggleLedD15.GPIO_PinConfig.GPIO_pinNum =GPIO_PIN_NO_15;
  toggleLedD15.GPIO_PinConfig.GPIO_pinMode = GPIO_MOD_OUT;
  toggleLedD15.GPIO_PinConfig.GPIO_pinSpeed = GPIO_SPEEDFAST;
  toggleLedD15.GPIO_PinConfig.GPIO_OPtype = GPIO_OPTYPE_PP;
  toggleLedD15.GPIO_PinConfig.GPIO_pinPuPdControl= GPIO_NO_PUPD;
  
  GPIO_Init(&toggleLedD15);
  buttonExtI.pGPIOx= GPIOA_REG;
  buttonExtI.GPIO_PinConfig.GPIO_pinNum =GPIO_PIN_NO_0;
  buttonExtI.GPIO_PinConfig.GPIO_pinMode = GPIO_MOD_IT_RT;
  buttonExtI.GPIO_PinConfig.GPIO_pinPuPdControl= GPIO_PD;
  GPIO_Init(&buttonExtI);
  uint8_t val;
  //IRQ configuration
  GPIO_IRQConfig(IRQ_EXTI0,ENABLE);
  GPIO_IQRPriorityConfig(IRQ_EXTI0,NVIC_IRQ_PRI0);
  //NVIC_EnableIRQ(EXTI0_IRQn);
  //NVIC_SetPriority(EXTI0_IRQn,1);

  while(1)
  {
     //val= GPIO_ReadPin(GPIOA_REG, GPIO_PIN_NO_0);
    
      
      GPIO_TogglePin(GPIOD_REG, GPIO_PIN_NO_13);
      GPIO_TogglePin(GPIOD_REG, GPIO_PIN_NO_14);
      GPIO_WritePin(GPIOD_REG,GPIO_PIN_NO_15, SET);
      delay(500000);
  }
}
void EXTI0_IRQHandler()
{
  GPIO_Handling(GPIO_PIN_NO_0);
  GPIO_TogglePin(GPIOD_REG, GPIO_PIN_NO_12);
}
