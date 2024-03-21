
#### 前置准备

 [torch 1.0.0 源码克隆、编译](giteaz:3000/wiki/github-gitee-GITEA#pytorch-v100)



#### 编译命令

```shell
g++ -o simple_nn.elf  simple_nn.cpp -std=c++14 -I /home/z/torch-repo/pytorch/torch/csrc/api/include -I /home/z/torch-repo/pytorch/torch/lib/include/   -L/home/z/torch-repo/pytorch/torch/lib -ltorch -lc10 -lcaffe2   -Wl,-rpath,/home/z/torch-repo/pytorch/torch/lib 

```


#### 编译产物

```shell

ls -lh  ./simple_nn.elf
# -rwxrwxrwx 1 z z 325K  3月 19 01:02 ./simple_nn.elf

./simple_nn.elf
# Output Tensor:  0.1329  0.3199  0.0247  0.0474 -0.1066  0.1654  0.1784 -0.0484  0.0771 -0.3323
#  0.0414  0.2583 -0.3015 -0.2569 -0.5553 -0.4284  0.4967 -0.1668  0.4003 -0.2204
#  0.0567 -0.0019 -0.1972  0.1640  0.1682 -0.1471 -0.2888 -0.1410  0.4073 -0.2272
# -0.4251  0.3480  0.1586 -0.1181 -0.2738  0.0413 -0.0257  0.0932  0.1334 -0.2221
#  0.2962  0.1109  0.0880  0.0808 -0.2932  0.2499  0.4288  0.2070 -0.1896  0.1968
# [ Variable[CPUFloatType]{5,10} ]

```


#### frida 小试
```frida --file ./simple_nn.elf --debug --pause``` , 输入js脚本```Process.enumerateModules().map(k=>k.name)``` ， 获得模块列表
```javascript
[
    "simple_nn.elf",
    "linux-vdso.so.1",
    "libtorch.so.1",
    "libc10.so",
    "libcaffe2.so",
    "libstdc++.so.6.0.30",
    "libgcc_s.so.1",
    "libc.so.6",
    "libm.so.6",
    "ld-linux-x86-64.so.2",
    "libnuma.so.1.0.0",
    "libmpi_cxx.so.40.30.1",
    "libmpi.so.40.30.2",
    "libopen-pal.so.40.30.2",
    "libopen-rte.so.40.30.2",
    "libhwloc.so.15.5.2",
    "libevent_core-2.1.so.7.0.1",
    "libevent_pthreads-2.1.so.7.0.1",
    "libz.so.1.2.11",
    "libudev.so.1.7.2",
    "libpthread.so.0",
    "frida-agent-64.so",
    "libdl.so.2",
    "librt.so.1"
]
```

经过人工过滤，给出 ```frida-trace  -I "simple_nn.elf"  -I "libtorch.so.1"  -I "libc10.so"  -I "libcaffe2.so"   --file ./simple_nn.elf```