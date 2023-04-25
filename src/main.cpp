#include "main.h"
using namespace pros;
// Chassis constructor
Drive chassis(
    // Left Chassis Ports (negative port will reverse it!)
    {11, -12, -13},
    // Right Chassis Ports (negative port will reverse it!)
    {18, 19, -20},
    // IMU Port
    2,
    // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
    2.75,
    // Cartridge RPM
    600,
    // External Gear Ratio
    .8);
void initialize() {
  master.clear();
  ez::print_ez_template();
  delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0);
  chassis.set_curve_default(0, 0);
  chassis_default_constants();
  chassis_exit_condition_defaults();
  ez::as::auton_selector.add_autons({
      Auton("Right Side 1", right_side_1),
  });
  chassis.initialize();
  ez::as::initialize();
  Task flywheel_task([&] { flywheel.fly_control(); });
}

void disabled() { 
  master.clear();
  flywheel.set_mode(3);
}

void competition_initialize() { master.clear(); }

void autonomous() {
  master.clear();
  Task autonomous_data_export_task(autonomous_data_export);
  chassis.reset_pid_targets();
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  ez::as::auton_selector.call_selected_auton();
}

void opcontrol() {
  master.clear();
  flywheel.set_mode(1);
  Task drive_data_export_task(driver_data_export);
  Task intake_task(intake_control_function);
  Task endgame_task(endgame_control_function);
  Task tongue_task(tongue_control_function);
  Task speed_task(speed_control_function);
  chassis.set_drive_brake(E_MOTOR_BRAKE_COAST);
  while (true) {
    // tongue_up_speed is tongue up idle voltage
    tongue_up_speed = 2600;
    // tongue_down_speed is tongue down idle voltage
    tongue_down_speed = 3300;
    chassis.arcade_standard(ez::SPLIT);
    delay(ez::util::DELAY_TIME);
  }
}