/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_MTU2.c
* Version      : 1.7.0
* Device(s)    : R5F565NEDxFP
* Description  : This file implements device driver for Config_MTU2.
* Creation Date: 2019-11-05
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_MTU2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU2_Create
* Description  : This function initializes the MTU2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU2_Create(void)
{
    /* Release MTU channel 2 from stop state */
    MSTP(MTU3) = 0U;

    /* Stop MTU channel 2 counter */
    MTU.TSTRA.BIT.CST2 = 0U;

    /* MTU channel 2 is used as normal mode */
    MTU.TSYRA.BIT.SYNC2 = 0U;
    MTU2.TCR.BYTE = _00_MTU_PCLK_1 | _00_MTU_CKCL_DIS;
    MTU2.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU2.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TCIEV_DISABLE | _00_MTU_TTGE_DISABLE;
    MTU2.TIOR.BYTE = _00_MTU_IOA_DISABLE | _00_MTU_IOB_DISABLE;
    MTU2.TGRA = _FFFF_TGRA2_VALUE;
    MTU2.TGRB = _FFFF_TGRB2_VALUE;

    R_Config_MTU2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU2_Start
* Description  : This function starts the MTU2 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU2_Start(void)
{
    /* Start MTU channel 2 counter */
    MTU.TSTRA.BIT.CST2 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU2_Stop
* Description  : This function stops the MTU2 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU2_Stop(void)
{
    /* Stop MTU channel 2 counter */
    MTU.TSTRA.BIT.CST2 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */

unsigned long timer_gettick(void)
{
    unsigned long cycles;

    /* Stop the lower 16-bit counter (it makes also the upper 16-bit counter stop) */
    R_Config_MTU2_Stop();

    /* Combine two 16-bit counters to form 32-bit counter value */
    cycles =  ((unsigned long)(MTU2.TCNT) &  0xffff); 
    cycles |= ((unsigned long)(MTU1.TCNT) << 16);

    /* Resume the lower 16-bit counter (it makes also the upper 16-bit counter resume) */
    R_Config_MTU2_Start();

    return cycles;
}

/* End user code. Do not edit comment generated here */   
