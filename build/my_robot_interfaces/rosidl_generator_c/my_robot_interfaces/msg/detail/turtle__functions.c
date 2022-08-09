// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/Turtle.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/turtle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
my_robot_interfaces__msg__Turtle__init(my_robot_interfaces__msg__Turtle * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    my_robot_interfaces__msg__Turtle__fini(msg);
    return false;
  }
  // x
  // y
  // theta
  return true;
}

void
my_robot_interfaces__msg__Turtle__fini(my_robot_interfaces__msg__Turtle * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // x
  // y
  // theta
}

my_robot_interfaces__msg__Turtle *
my_robot_interfaces__msg__Turtle__create()
{
  my_robot_interfaces__msg__Turtle * msg = (my_robot_interfaces__msg__Turtle *)malloc(sizeof(my_robot_interfaces__msg__Turtle));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__Turtle));
  bool success = my_robot_interfaces__msg__Turtle__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__Turtle__destroy(my_robot_interfaces__msg__Turtle * msg)
{
  if (msg) {
    my_robot_interfaces__msg__Turtle__fini(msg);
  }
  free(msg);
}


bool
my_robot_interfaces__msg__Turtle__Sequence__init(my_robot_interfaces__msg__Turtle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  my_robot_interfaces__msg__Turtle * data = NULL;
  if (size) {
    data = (my_robot_interfaces__msg__Turtle *)calloc(size, sizeof(my_robot_interfaces__msg__Turtle));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__Turtle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__Turtle__fini(&data[i - 1]);
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
my_robot_interfaces__msg__Turtle__Sequence__fini(my_robot_interfaces__msg__Turtle__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__Turtle__fini(&array->data[i]);
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

my_robot_interfaces__msg__Turtle__Sequence *
my_robot_interfaces__msg__Turtle__Sequence__create(size_t size)
{
  my_robot_interfaces__msg__Turtle__Sequence * array = (my_robot_interfaces__msg__Turtle__Sequence *)malloc(sizeof(my_robot_interfaces__msg__Turtle__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__Turtle__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__Turtle__Sequence__destroy(my_robot_interfaces__msg__Turtle__Sequence * array)
{
  if (array) {
    my_robot_interfaces__msg__Turtle__Sequence__fini(array);
  }
  free(array);
}
