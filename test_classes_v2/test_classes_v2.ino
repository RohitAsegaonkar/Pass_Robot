/***** MPU *****/
#define MPU 0
/***************/

/********** Encoder **********/
#define encoder_x 0
#define encoder_y 0
/*****************************/

/********** MOTORS **********/
#define motor1 0 
#define motor2 0
#define motor3 0
/****************************/

/*************** PISTON ***************/
#define piston_gripper_extend 0
#define piston_gripper_retract 0
#define piston_Throwing_extend 0
#define piston_Throwing_retract 0
/**************************************/

#include "Encoder.h"
#include "Mpu.h"
#include "Motor.h"
#include "Manual.h"
#include "Piston.h"

Manual M;

Encoder X(21, 50);
Encoder Y(2, 52);

Mpu mpu;

Motor M1(26, M.dirW1, 6);
Motor M2(38, M.dirW2, 12);
Motor M3(36, M.dirW3, 11);

Piston Gripper(41, 39), Throwing(37, 35);

/*
 * ENCODER TO BE TESTED   
 */
#if encoder_x 
    void UpdateXEncoder()
    {
      X.updateEncoder();
    }
#endif

#if encoder_y 
    void UpdateYEncoder()
    {
      Y.updateEncoder();
    }
#endif

void setup()
{

  Serial.begin(115200);
  Serial2.begin(115200);

    #if encoder_x 
        attachInterupt();  // ?? @SRohit
    #endif

    #if encoder_y 
        attachInterupt();  // ?? @SRohit
    #endif

}

void loop()
{
/*************** MPU ***************/
    #if MPU
        float Yaw;
        Yaw = mpu.readMpu(2);
        Serial.print(" Yaw : \t" );
        Serial.println(Yaw);
    #endif 
/***********************************/

/********** Encoder **********/
    #if encoder_x

    #endif

    #if encoder_y

    #endif

/*****************************/

/*************** MOTORS ***************/
    #if motor1
        M1.SetDirection();
        M1.SetSpeed(150);
    #endif

    #if motor2
        M2.SetDirection();
        M2.SetSpeed(150);
    #endif

    #if motor3
        M3.SetDirection();
        M3.SetSpeed(150);
    #endif
/***************************************/

/*************** PISTON ***************/
    #if piston_gripper_extend
        Gripper.Extend();
    #endif

    #if piston_gripper_retract
        Gripper.Retract();
    #endif

    #if piston_Throwing_extend
        Throwing.Extend();
    #endif

    #if piston_Throwing_retract
        Throwing.Retract();
    #endif
/***************************************/

}