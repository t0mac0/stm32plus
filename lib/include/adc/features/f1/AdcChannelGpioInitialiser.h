/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once

// ensure the MCU series is correct
#ifndef STM32PLUS_F1
#error This class can only be used with the STM32F1 series
#endif


namespace stm32plus {


  /**
   * Utility class for the sole purpose of initialising a GPIO pin for the ADC.
   * @tparam TAdcNumber The ADC number (1..3)
   * @tparam TChannelNumber The channel number (0..15)
   */

  template<uint8_t TAdcNumber,uint8_t TChannelNumber>
  struct AdcChannelGpioInitiaiser {

    /**
     * Initialise the GPIO pin. The idea here is that the conditional statements are on constants
     * and so can be evaluated at compile time. The optimiser will eliminate everything except
     * the two assignments for the correct port and pin.
     */

    static void initialiseGpioPin() {

      GPIO_TypeDef *port;
      uint16_t pin;

      static_assert(TAdcNumber>=1 && TAdcNumber<=3,"TAdcNumber out of range");

      if(TAdcNumber==1) {
        switch(TChannelNumber) {
          case 0: port=GPIOA; pin=GPIO_Pin_0; break;
          case 1: port=GPIOA; pin=GPIO_Pin_1; break;
          case 2: port=GPIOA; pin=GPIO_Pin_2; break;
          case 3: port=GPIOA; pin=GPIO_Pin_3; break;
          case 4: port=GPIOA; pin=GPIO_Pin_4; break;
          case 5: port=GPIOA; pin=GPIO_Pin_5; break;
          case 6: port=GPIOA; pin=GPIO_Pin_6; break;
          case 7: port=GPIOA; pin=GPIO_Pin_7; break;
          case 8: port=GPIOB; pin=GPIO_Pin_0; break;
          case 9: port=GPIOB; pin=GPIO_Pin_1; break;
          case 10: port=GPIOC; pin=GPIO_Pin_0; break;
          case 11: port=GPIOC; pin=GPIO_Pin_1; break;
          case 12: port=GPIOC; pin=GPIO_Pin_2; break;
          case 13: port=GPIOC; pin=GPIO_Pin_3; break;
          case 14: port=GPIOC; pin=GPIO_Pin_4; break;
          case 15: port=GPIOC; pin=GPIO_Pin_5; break;
        }
      }
      else if(TAdcNumber==2) {
        switch(TChannelNumber) {
          case 0: port=GPIOA; pin=GPIO_Pin_0; break;
          case 1: port=GPIOA; pin=GPIO_Pin_1; break;
          case 2: port=GPIOA; pin=GPIO_Pin_2; break;
          case 3: port=GPIOA; pin=GPIO_Pin_3; break;
          case 4: port=GPIOA; pin=GPIO_Pin_4; break;
          case 5: port=GPIOA; pin=GPIO_Pin_5; break;
          case 6: port=GPIOA; pin=GPIO_Pin_6; break;
          case 7: port=GPIOA; pin=GPIO_Pin_7; break;
          case 8: port=GPIOB; pin=GPIO_Pin_0; break;
          case 9: port=GPIOB; pin=GPIO_Pin_1; break;
          case 10: port=GPIOC; pin=GPIO_Pin_0; break;
          case 11: port=GPIOC; pin=GPIO_Pin_1; break;
          case 12: port=GPIOC; pin=GPIO_Pin_2; break;
          case 13: port=GPIOC; pin=GPIO_Pin_3; break;
          case 14: port=GPIOC; pin=GPIO_Pin_4; break;
          case 15: port=GPIOC; pin=GPIO_Pin_5; break;
        }
      }
      else if(TAdcNumber==3) {
        switch(TChannelNumber) {                        // not all channels are available on ADC3
          case 0: port=GPIOA; pin=GPIO_Pin_0; break;
          case 1: port=GPIOA; pin=GPIO_Pin_1; break;
          case 2: port=GPIOA; pin=GPIO_Pin_2; break;
          case 3: port=GPIOA; pin=GPIO_Pin_3; break;
          case 4: port=GPIOF; pin=GPIO_Pin_6; break;
          case 5: port=GPIOF; pin=GPIO_Pin_7; break;
          case 6: port=GPIOF; pin=GPIO_Pin_8; break;
          case 7: port=GPIOF; pin=GPIO_Pin_9; break;
          case 8: port=GPIOF; pin=GPIO_Pin_10; break;
          case 10: port=GPIOC; pin=GPIO_Pin_0; break;
          case 11: port=GPIOC; pin=GPIO_Pin_1; break;
          case 12: port=GPIOC; pin=GPIO_Pin_2; break;
          case 13: port=GPIOC; pin=GPIO_Pin_3; break;
        }
      }

      // initialise the pin

      GpioPinInitialiser::initialise(port,pin);   // this minimal overload is for analog input
    }
  };
}
