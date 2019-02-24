#include "include/types.h"
#include "include/DCmotor.h"
#include "include/PWM.h"

struct State {
	uint8 DutyCycle;
	uint8 Direction;
			};

typedef const struct State Motor1;

int main(void)
{
	//DC_Motor_Init(MOTOR1_EN,MOTOR1_DIR_A,MOTOR1_DIR_B);
	DC_Motor_Init(MOTOR2_EN,MOTOR2_DIR_A,MOTOR2_DIR_B);
	
	
	DC_MotorMove(MOTOR1_EN,MOTOR1_DIR_A,MOTOR1_DIR_B,FORWARD);
	DC_MotorMove(MOTOR2_EN,MOTOR2_DIR_A,MOTOR2_DIR_B,FORWARD);

	while (1) 
    {
		PWM_init(0);
		_delay_ms(5000);

		PWM_init(25);
		_delay_ms(5000);
		
		PWM_init(75);
		_delay_ms(5000);

		PWM_init(25);
		_delay_ms(5000);			
    }
}

