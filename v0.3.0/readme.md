```shell
g++ -I/home/z/torch-v0.3.0/pytorch/torch/lib/include  -o simple_nn simple_nn.cpp   /home/z/torch-v0.3.0/pytorch/torch/lib/build/libTH.so -Wl,-rpath,/home/z/torch-v0.3.0/pytorch/torch/lib/build
```

报错如下


```
simple_nn.cpp: In function ‘int main()’:
simple_nn.cpp:20:33: error: cannot convert ‘THFloatTensor*’ to ‘float’
   20 |     THFloatTensor_addmm(hidden, bias1, input, weights1);
      |                                 ^~~~~
      |                                 |
      |                                 THFloatTensor*
In file included from generic/THTensorMath.h:1,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THGenerateFloatTypes.h:10,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THGenerateAllTypes.h:10,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THTensor.h:32,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/TH.h:17,
                 from simple_nn.cpp:3:
/home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/generic/THTensorMath.h:69:49: note:   initializing argument 2 of ‘void THFloatTensor_addmm(THFloatTensor*, float, THFloatTensor*, float, THFloatTensor*, THFloatTensor*)’
   69 | TH_API void THTensor_(addmm)(THTensor *r_, real beta, THTensor *t, real alpha, THTensor *mat1, THTensor *mat2);
simple_nn.cpp:21:23: error: too many arguments to function ‘void THFloatTensor_cadd(THFloatTensor*, THFloatTensor*, float, THFloatTensor*)’
   21 |     THFloatTensor_cadd(hidden, hidden, 1, bias1, 1);  // 加上偏置
      |     ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/TH.h:4,
                 from simple_nn.cpp:3:
/home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THTensor.h:8:39: note: declared here
    8 | #define THTensor_(NAME)   TH_CONCAT_4(TH,Real,Tensor_,NAME)
      |                                       ^~
/home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THGeneral.h:118:37: note: in definition of macro ‘TH_CONCAT_4_EXPAND’
  118 | #define TH_CONCAT_4_EXPAND(x,y,z,w) x ## y ## z ## w
      |                                     ^
/home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THTensor.h:8:27: note: in expansion of macro ‘TH_CONCAT_4’
    8 | #define THTensor_(NAME)   TH_CONCAT_4(TH,Real,Tensor_,NAME)
      |                           ^~~~~~~~~~~
/home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/generic/THTensorMath.h:52:13: note: in expansion of macro ‘THTensor_’
   52 | TH_API void THTensor_(cadd)(THTensor *r_, THTensor *t, real value, THTensor *src);
      |             ^~~~~~~~~
simple_nn.cpp:22:5: error: ‘THFloatTensor_relu’ was not declared in this scope; did you mean ‘THFloatTensor_gels’?
   22 |     THFloatTensor_relu(hidden, hidden);  // 使用ReLU激活函数
      |     ^~~~~~~~~~~~~~~~~~
      |     THFloatTensor_gels
simple_nn.cpp:26:33: error: cannot convert ‘THFloatTensor*’ to ‘float’
   26 |     THFloatTensor_addmm(output, bias2, hidden, weights2);
      |                                 ^~~~~
      |                                 |
      |                                 THFloatTensor*
In file included from generic/THTensorMath.h:1,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THGenerateFloatTypes.h:10,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THGenerateAllTypes.h:10,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/THTensor.h:32,
                 from /home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/TH.h:17,
                 from simple_nn.cpp:3:
/home/z/torch-v0.3.0/pytorch/torch/lib/include/TH/generic/THTensorMath.h:69:49: note:   initializing argument 2 of ‘void THFloatTensor_addmm(THFloatTensor*, float, THFloatTensor*, float, THFloatTensor*, THFloatTensor*)’
   69 | TH_API void THTensor_(addmm)(THTensor *r_, real beta, THTensor *t, real alpha, THTensor *mat1, THTensor *mat2);

```