#pragma config(Sensor, dgtl4,  bottom,         sensorTouch)
#pragma config(Sensor, dgtl1,  top,            sensorTouch)
#pragma config(Sensor, dgtl9,  encoderA,       sensorQuadEncoder)
#pragma config(Motor,  port1,           left_motor,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          right_motor,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float getTimeSec() {
	return time1[T1] / 1000.0;
}


// motor + encoder

// inches
const float SPROCKET_DIAMETER = 1.5;
const float SPROCKET_CIRCUMFERENCE = SPROCKET_DIAMETER * 3.1415;

// inches
const float BOTTOM_HEIGHT = 4;
const float TOP_HEIGHT = 25.5 - 0.5;

void set(float speed) {
	if (SensorValue[top] && speed > 0) {
		set(0);
	}
	else if (SensorValue[bottom] && speed < 0) {
		set(0);
	}
	else {
		motor[left_motor] = -speed;
		motor[right_motor] = speed;
	}
}

float getHeight() {
	return BOTTOM_HEIGHT + SensorValue[encoderA] / 360.0 * SPROCKET_CIRCUMFERENCE * 2;
}

// control loop

float kP = 50;
float kG = 20;
const float kS = 0;

float getVoltage(float target, float measurement) {
	float error = target - measurement;

	if (abs(error) < 0.1) return 0;

	return kG + kS * sgn(error) + kP * error;
}

float targetHeight = 0;

void setTargetHeight(float height) {
	if (height < BOTTOM_HEIGHT) {
		setTargetHeight(BOTTOM_HEIGHT);
	}
	else if (height > TOP_HEIGHT) {
		setTargetHeight(TOP_HEIGHT);
	}
	else {
		targetHeight = height;
	}
}

// main

float h;
float t = BOTTOM_HEIGHT;

task main()
{
	while (1) {
		if (SensorValue[bottom]) {
			SensorValue[encoderA] = 0;
		}

		if (SensorValue[top]) {
			SensorValue[encoderA] = TOP_HEIGHT; // Isnt top height in inches so this wont convert properly right?
		}

		setTargetHeight(t);

		h = getHeight();

		set(getVoltage(targetHeight, getHeight()));
	}
}