// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_EXPORT __attribute__ ((dllexport))
    #define ROSIDL_IMPORT __attribute__ ((dllimport))
  #else
    #define ROSIDL_EXPORT __declspec(dllexport)
    #define ROSIDL_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROSIDL_BUILDING_DLL
    #define ROSIDL_PUBLIC ROSIDL_EXPORT
  #else
    #define ROSIDL_PUBLIC ROSIDL_IMPORT
  #endif
  #define ROSIDL_LOCAL
#else
  #define ROSIDL_EXPORT __attribute__ ((visibility("default")))
  #define ROSIDL_IMPORT
  #if __GNUC__ >= 4
    #define ROSIDL_PUBLIC __attribute__ ((visibility("default")))
    #define ROSIDL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROSIDL_PUBLIC
    #define ROSIDL_LOCAL
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
