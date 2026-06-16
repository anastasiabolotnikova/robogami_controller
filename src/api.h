#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define RobogamiController_DLLIMPORT __declspec(dllimport)
#  define RobogamiController_DLLEXPORT __declspec(dllexport)
#  define RobogamiController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define RobogamiController_DLLIMPORT __attribute__((visibility("default")))
#    define RobogamiController_DLLEXPORT __attribute__((visibility("default")))
#    define RobogamiController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define RobogamiController_DLLIMPORT
#    define RobogamiController_DLLEXPORT
#    define RobogamiController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef RobogamiController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define RobogamiController_DLLAPI
#  define RobogamiController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef RobogamiController_EXPORTS
#    define RobogamiController_DLLAPI RobogamiController_DLLEXPORT
#  else
#    define RobogamiController_DLLAPI RobogamiController_DLLIMPORT
#  endif // RobogamiController_EXPORTS
#  define RobogamiController_LOCAL RobogamiController_DLLLOCAL
#endif // RobogamiController_STATIC