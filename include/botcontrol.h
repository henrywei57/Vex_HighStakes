// include/botcontrol.h
   #pragma once

   void driver();

   float to_volt(float percent);
   float deadband(float input, float width);

   void nextState();

   void initializeArm();
   
   void idlePos();

   void nextRing();