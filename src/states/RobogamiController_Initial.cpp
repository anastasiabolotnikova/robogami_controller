#include "RobogamiController_Initial.h"

#include "../RobogamiController.h"

void RobogamiController_Initial::configure(const mc_rtc::Configuration & config)
{
}

void RobogamiController_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<RobogamiController &>(ctl_);
}

bool RobogamiController_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<RobogamiController &>(ctl_);
  output("OK");
  return true;
}

void RobogamiController_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<RobogamiController &>(ctl_);
}

EXPORT_SINGLE_STATE("RobogamiController_Initial", RobogamiController_Initial)
