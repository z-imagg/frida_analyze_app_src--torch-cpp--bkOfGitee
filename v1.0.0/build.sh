#!/usr/bin/env bash

cd /fridaAnlzAp/torch-cpp/v1.0.0/

g++ -g1 -o simple_nn.elf  simple_nn.cpp -std=c++14 -I /home/z/torch-repo/pytorch/torch/csrc/api/include -I /home/z/torch-repo/pytorch/torch/lib/include/   -L/home/z/torch-repo/pytorch/torch/lib -ltorch -lc10 -lcaffe2   -Wl,-rpath,/home/z/torch-repo/pytorch/torch/lib 