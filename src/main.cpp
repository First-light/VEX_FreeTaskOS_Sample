#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include "_includes.h"

using namespace vex;

competition Competition;



int main()
{
  vexcodeInit();
// Initializing Robot Configuration. DO NOT REMOVE!

  Competition.autonomous(autonomous_task);
  Competition.drivercontrol(manual_task);

  while (true)
  {
    wait(100, msec);
  }
}
