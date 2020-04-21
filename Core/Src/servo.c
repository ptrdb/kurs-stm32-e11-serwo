/* The MIT License
 *
 * Copyright (c) 2020 Piotr Duba
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "servo.h"
#include "tim.h"

/*
 * ang - kat obrotu walu serwomechanizmu
 * mode - tryb obrotu zgodnie/przeciwnie do wskazowek zegara
 */
void set_ang(uint16_t ang, uint8_t mode)
{
	uint16_t val;

	if(ang > ANGLE_MAX)
	{
		ang = ANGLE_MAX;
	}
	else if (ang < ANGLE_MIN)
	{
		ang = ANGLE_MIN;
	}

	if(mode)
	{
		val = PWM_MIN + ((ang - ANGLE_MIN) * STEP) / 1000;
	}
	else
	{
		val = PWM_MAX - ((ang - ANGLE_MIN) * STEP) / 1000;
	}

	__HAL_TIM_SET_COMPARE(&TIM_NO, TIM_CH_NO, val);
}
