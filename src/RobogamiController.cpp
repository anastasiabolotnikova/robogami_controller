#include "RobogamiController.h"

RobogamiController::RobogamiController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config)
{

  mc_rtc::log::success("RobogamiController init done ");
}

bool RobogamiController::run()
{
  return mc_control::fsm::Controller::run();
}

void RobogamiController::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::fsm::Controller::reset(reset_data);

  // Low joint weights in posture task for passive DoFs
  std::map<std::string, double> jointWeights = {{"x_l1rotx", 0.001},
                                                {"x_l1roty", 0.001},
                                                {"x_l1top", 0.001},
                                                {"x_l2rotx", 0.001},
                                                {"x_l2roty", 0.001},
                                                {"x_l2top", 0.001},
                                                {"x_l3rotx", 0.001},
                                                {"x_l3roty", 0.001},
                                                {"x_l3top", 0.001},
                                                {"l1topBase", 0.001},
                                                {"l2TopMove", 0.001},
                                                {"l3TopMove", 0.001}};
                                                
  getPostureTask("robogami")->jointWeights(jointWeights);

}


