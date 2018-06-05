/*******************************************************************************
 * StmPlusPlus: object-oriented library implementing device drivers for
 * STM32F3 and STM32F4 MCU
 * *****************************************************************************
 * Copyright (C) 2016-2017 Mikhail Kulesh
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#ifndef HARDWARE_MAP_H_
#define HARDWARE_MAP_H_

#include "StmPlusPlus/HardwareLayout.h"

namespace HardwareLayout {

class Usart1 : public Usart
{
public:
    Usart1 (): Usart{USART1, GPIO_AF7_USART1, USART1_IRQn}
    {
        disableClock();
    }
    virtual void enableClock () const
    {
        if (!__HAL_RCC_USART1_IS_CLK_ENABLED())
        {
            __HAL_RCC_USART1_CLK_ENABLE();
        }
    }
    virtual void disableClock () const
    {
        __HAL_RCC_USART1_CLK_DISABLE();
    }
};

class Usart2 : public Usart
{
public:
    Usart2 (): Usart{USART2, GPIO_AF7_USART2, USART2_IRQn}
    {
        disableClock();
    }
    virtual void enableClock () const
    {
        if (!__HAL_RCC_USART2_IS_CLK_ENABLED())
        {
            __HAL_RCC_USART2_CLK_ENABLE();
        }
    }
    virtual void disableClock () const
    {
        __HAL_RCC_USART2_CLK_DISABLE();
    }
};

} // end namespace
#endif
