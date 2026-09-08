#pragma once

#include <mc_control/mc_controller.h>
#include <mc_control/fsm/TVMController.h>

#include "api.h"

struct RobogamiController_DLLAPI RobogamiController : public mc_control::fsm::TVMController
{
  RobogamiController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);

  bool run() override;

  void reset(const mc_control::ControllerResetData & reset_data) override;
};