#ifndef PHYSICAL_H
#define PHYSICAL_H

#if defined(__cplusplus)
extern "C"
{
#endif

void setupMotors();
void enableMotors(int en);
void leftMotorDir(int dir);
void rightMotorDir(int dir);

#if defined(__cplusplus)
}
#endif

#endif
