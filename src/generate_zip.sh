#!/usr/bin/env bash

project_name='prog3_unit1_text_v2023_1'
source_code='
        Text.h Text.cpp
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}