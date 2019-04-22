/***********************************************************************************
 * @file adc.h
 * @brief Contains ADC routine
 * @author Vikrant Waje
 * @date April 11, 2018
 * @Reference: TIVA ware example code: adc.c found within examples/peripherals/
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "adc.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Setup the ADC peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void adc_init(void)
{
    //
    // The ADC0 peripheral must be enabled for use.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

    //
    // Enable sample sequence 3 with a processor signal trigger.  Sequence 3
    // will do a single sample when the processor sends a signal to start the
    // conversion.  Each ADC module has 4 programmable sequences, sequence 0
    // to sequence 3.  This example is arbitrarily using sequence 3.
    //
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

    //
    // Configure step 0 on sequence 3.  Sample channel 0 (ADC_CTL_CH0) in
    // single-ended mode (default) and configure the interrupt flag
    // (ADC_CTL_IE) to be set when the sample is done.  Tell the ADC logic
    // that this is the last conversion on sequence 3 (ADC_CTL_END).  Sequence
    // 3 has only one programmable step.  Sequence 1 and 2 have 4 steps, and
    // sequence 0 has 8 programmable steps.  Since we are only doing a single
    // conversion using sequence 3 we will only configure step 0.  For more
    // information on the ADC sequences and steps, reference the datasheet.
    //
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0 | ADC_CTL_IE |
    ADC_CTL_END);

    //
    // Since sample sequence 3 is now configured, it must be enabled.
    //
    ADCSequenceEnable(ADC0_BASE, 3);

    //
    // Clear the interrupt status flag.  This is done to make sure the
    // interrupt flag is cleared before we sample.
    //
    ADCIntClear(ADC0_BASE, 3);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read from  ADC .


 @param: val: Pointer to variable in which data that is read is to be stored
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void read_adc(float *converted_val){
    uint32_t val = 0;
    //
    // Trigger the ADC conversion.
    //
    ADCProcessorTrigger(ADC0_BASE, 3);

    //
    // Wait for conversion to be completed.
    //
    while(!ADCIntStatus(ADC0_BASE, 3, false))
    {
    }

    //
    // Clear the ADC interrupt flag.
    //
    ADCIntClear(ADC0_BASE, 3);

    //
    // Read ADC Value.
    //
    ADCSequenceDataGet(ADC0_BASE, 3, &val);
    *converted_val = (3.3/4096)*val;
}
