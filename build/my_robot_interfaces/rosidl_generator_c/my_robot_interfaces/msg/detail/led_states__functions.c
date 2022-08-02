// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/LedStates.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/led_states__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `led_states`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
my_robot_interfaces__msg__LedStates__init(my_robot_interfaces__msg__LedStates * msg)
{
  if (!msg) {
    return false;
  }
  // led_states
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->led_states, 0)) {
    my_robot_interfaces__msg__LedStates__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__msg__LedStates__fini(my_robot_interfaces__msg__LedStates * msg)
{
  if (!msg) {
    return;
  }
  // led_states
  rosidl_runtime_c__int64__Sequence__fini(&msg->led_states);
}

my_robot_interfaces__msg__LedStates *
my_robot_interfaces__msg__LedStates__create()
{
  my_robot_interfaces__msg__LedStates * msg = (my_robot_interfaces__msg__LedStates *)malloc(sizeof(my_robot_interfaces__msg__LedStates));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__LedStates));
  bool success = my_robot_interfaces__msg__LedStates__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__LedStates__destroy(my_robot_interfaces__msg__LedStates * msg)
{
  if (msg) {
    my_robot_interfaces__msg__LedStates__fini(msg);
  }
  free(msg);
}


bool
my_robot_interfaces__msg__LedStates__Sequence__init(my_robot_interfaces__msg__LedStates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  my_robot_interfaces__msg__LedStates * data = NULL;
  if (size) {
    data = (my_robot_interfaces__msg__LedStates *)calloc(size, sizeof(my_robot_interfaces__msg__LedStates));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__LedStates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__LedStates__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_interfaces__msg__LedStates__Sequence__fini(my_robot_interfaces__msg__LedStates__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__LedStates__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_interfaces__msg__LedStates__Sequence *
my_robot_interfaces__msg__LedStates__Sequence__create(size_t size)
{
  my_robot_interfaces__msg__LedStates__Sequence * array = (my_robot_interfaces__msg__LedStates__Sequence *)malloc(sizeof(my_robot_interfaces__msg__LedStates__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__LedStates__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__LedStates__Sequence__destroy(my_robot_interfaces__msg__LedStates__Sequence * array)
{
  if (array) {
    my_robot_interfaces__msg__LedStates__Sequence__fini(array);
  }
  free(array);
}
