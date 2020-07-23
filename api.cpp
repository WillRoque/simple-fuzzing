// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// Implementation of "api".
#include "api.h"

#include <iostream>
#include <vector>

// Do some computations with 'str', return the result.
// This function contains a bug. Can you spot it?
size_t DoStuff(const std::string &str) {
//   std::vector<int> Vec({0, 1, 2});
//   size_t Idx = 0;
//   if (str.size() > 5) Idx++;
//   if (str.find("foo") != std::string::npos) Idx++;
//   if (str.find("bar") != std::string::npos) Idx++;
//   return Vec[Idx];
  return 0;
}

size_t DoStuffWithMyStruct(struct MyStruct m) {
  // TODO: With this check the struct fuzzer sometimes takes several minutes to
  //       find the crash (only seen in the campaign run integration tests for
  //       now).
  //  if (m.extra_value > 100 && m.extra_value % 2 == 0) {
  std::string s(m.data, m.data_size);
  if (s.find("deadbeef") == 0) {
    *(char *)1 = 2;
  }
  //  }
  return 0;
}

int TriggerUndefinedBehaviorSanitizer() {
  int n = 23;
  n <<= 32;
  return n;
}

void LeakMemory() {
  void* p = malloc(6);
  if (p) {
    *(char*)p = 'B';
  }
}
