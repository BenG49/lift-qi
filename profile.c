// https://github.com/wpilibsuite/allwpilib/blob/main/wpimath/src/main/java/edu/wpi/first/math/trajectory/TrapezoidProfile.java
// https://docs.wpilib.org/en/stable/docs/software/advanced-controls/controllers/trapezoidal-profiles.html
// https://b2600047.smushcdn.com/2600047/wp-content/uploads/2019/10/Motion-Profile-Feature.jpg?lossy=1&strip=1&webp=0

float MAX_ACCEL, MAX_VEL;

typedef

float getSetpoint(float *outputPosition, float *outputVelocity, float currentPosition, float currentVelocity, float elapsed_time) {
	float accel_time = MAX_ACCEL / MAX_VEL;

	float distance = outputPosition - currentPosition

	float halfway_distance = distance / 2;

	float accel_distance = currentVelocity * accel_time + 0.5 * accel_time ** 2;


	// d = vit + 0.5at^2
	// vf - vi = at

}
