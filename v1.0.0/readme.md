前置准备， [torch 1.0.0 源码克隆、编译](http://giteaz:3000/wiki/github-gitee-GITEA/src/commit/34588025a65ef7ce6dce37eec5051031eb618738#pytorch-v100)



编译命令， 

```shell
g++ -o simple_nn  simple_nn.cpp -std=c++14 -I /home/z/torch-repo/pytorch/torch/csrc/api/include -I /home/z/torch-repo/pytorch/torch/lib/include/   -L/home/z/torch-repo/pytorch/torch/lib -ltorch -lc10 -lcaffe2   -Wl,-rpath,/home/z/torch-repo/pytorch/torch/lib 

```