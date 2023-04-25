#include "main.h"
using namespace pros;
void drive_example() {
  chassis.set_drive_pid(24, 110, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, 110);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, 110);
  chassis.wait_drive();
}
void right_side_1() {
  intake_power(-100);
  chassis.set_drive_pid(45, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(15, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_power(100);
  delay(200);
  intake_power(20);
  delay(2000);
  intake_power(0);
  flywheel_power(0);
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-100);
  chassis.set_drive_pid(55, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  
}
void left_side(){
  //x, y
  // 3.5 ,36, 270
  flywheel.set_mode(1);
  flywheel.set_target(3000);
  intake_power(100);
  chassis.set_drive_pid(-1, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  //2.5, 36, 270
  chassis.set_drive_pid(9.5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  //12, 36, 270
  chassis.set_turn_pid(-9.352, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //12, 36, 279.352
  flywheel.fire_discs(2);
  pros::delay(900);
  //preloads fire
  chassis.set_turn_pid(54.352, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //12, 36, 225
  chassis.set_drive_pid(16.97, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //24, 48, 225
  chassis.set_turn_pid(-90, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //24, 48, 315
  intake_power(-50);
  //intake 3 stack on line
  chassis.set_drive_pid(16.97, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //36, 36, 315
  pros::delay(1000);
  chassis.set_drive_pid(-8.485, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  //30, 42, 315
  chassis.set_turn_pid(30.347, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //30, 42, 284.653
  flywheel.fire_discs(3);
  pros::delay(1350);
  //shoots 3 stack
  chassis.set_turn_pid(-30.347, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //30, 42, 315
  chassis.set_drive_pid(-8.485, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //24, 48, 315
  chassis.set_turn_pid(90, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //24, 48, 225;
  intake_power(-50);
  chassis.set_drive_pid(16.97, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  pros::delay(1000);
  //36, 60, 225
  chassis.set_turn_pid(-70.983, drive_speed*normal_speed_multiplier);
  chassis.wait_drive();
  //36, 60, 295.983
  intake_power(0);
  pros::delay(300);
  flywheel.fire_discs(3);
  //shoot last 3







} 