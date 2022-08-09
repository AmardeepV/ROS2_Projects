// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/turtle_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `turtles`
#include "my_robot_interfaces/msg/detail/turtle__functions.h"

bool
my_robot_interfaces__msg__TurtleArray__init(my_robot_interfaces__msg__TurtleArray * msg)
{
  if (!msg) {
    return false;
  }
  // turtles
  if (!my_robot_interfaces__msg__Turtle__Sequence__init(&msg->turtles, 0)) {
    my_robot_interfaces__msg__TurtleArray__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__msg__TurtleArray__fini(my_robot_interfaces__msg__TurtleArray * msg)
{
  if (!msg) {
    return;
  }
  // turtles
  my_robot_interfaces__msg__Turtle__Sequence__fini(&msg->turtles);
}

my_robot_interfaces__msg__TurtleArray *
my_robot_interfaces__msg__TurtleArray__create()
{
  my_robot_interfaces__msg__TurtleArray * msg = (my_robot_interfaces__msg__TurtleArray *)malloc(sizeof(my_robot_interfaces__msg__TurtleArray));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__TurtleArray));
  bool success = my_robot_interfaces__msg__TurtleArray__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__TurtleArray__destroy(my_robot_interfaces__msg__TurtleArray * msg)
{
  if (msg) {
    my_robot_interfaces__msg__TurtleArray__fini(msg);
  }
  free(msg);
}


bool
my_robot_interfaces__msg__TurtleArray__Sequence__init(my_robot_interfaces__msg__TurtleArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  my_robot_interfaces__msg__TurtleArray * data = NULL;
  if (size) {
    data = (my_robot_interfaces__msg__TurtleArray *)calloc(size, sizeof(my_robot_interfaces__msg__TurtleArray));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__TurtleArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__TurtleArray__fini(&data[i - 1]);
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
my_robot_interfaces__msg__TurtleArray__Sequence__fini(my_robot_interfaces__msg__TurtleArray__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__TurtleArray__fini(&array->data[i]);
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

my_robot_interfaces__msg__TurtleArray__Sequence *
my_robot_interfaces__msg__TurtleArray__Sequence__create(size_t size)
{
  my_robot_interfaces__msg__TurtleArray__Sequence * array = (my_robot_interfaces__msg__TurtleArray__Sequence *)malloc(sizeof(my_robot_interfaces__msg__TurtleArray__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__TurtleArray__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__TurtleArray__Sequence__destroy(my_robot_interfaces__msg__TurtleArray__Sequence * array)
{
  if (array) {
    my_robot_interfaces__msg__TurtleArray__Sequence__fini(array);
  }
  free(array);
}
