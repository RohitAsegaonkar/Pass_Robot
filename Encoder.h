#ifndef _ENCODER_H_
#define _ENCODER_H_
class Encoder{
   private:

  public:
         /******* Variables for the encoder *******/
         volatile int encodervalue;                                                // Count of pulses from encoder 1 and encoder 2
         volatile int a, b;
         int encoderPin , comparePin; 
         
         Encoder(int EP1,int CP1 ){
             encoderPin = EP1;
             comparePin = CP1;
             pinMode(encoderPin,INPUT_PULLUP);
             pinMode(comparePin,INPUT_PULLUP);

         }    
         void updateEncoder();  
};

     /*
 *  Function Name       : updateEncoder()
 *  Input               : No input required
 *  Output              : pulses of the x encoder stored in variable encodervalue1
 *  Logic               : The function will be called when the interrupt is triggered at the rising edge of channel A.
 *                        If the channel B is in phase with the channel A the count is incremented and decremented otherwise
 *  Example Call        : The function is called by the interrupt
 */
 void Encoder::updateEncoder()
{
    a = digitalRead(encoderPin);
    b = digitalRead(comparePin);

    if (b == 1)
        encodervalue++;
    if (b == 0)
        encodervalue--;

}
#endif
