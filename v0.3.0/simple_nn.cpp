#include <iostream>
extern "C" {
#include <TH/TH.h>
}

int main() {
    // 创建输入张量
    THFloatTensor* input = THFloatTensor_newWithSize1d(10);
    
    // 创建隐藏层权重和偏置
    THFloatTensor* weights1 = THFloatTensor_newWithSize2d(5, 10);
    THFloatTensor* bias1 = THFloatTensor_newWithSize1d(5);

    // 创建输出层权重和偏置
    THFloatTensor* weights2 = THFloatTensor_newWithSize2d(1, 5);
    THFloatTensor* bias2 = THFloatTensor_newWithSize1d(1);

    // 进行前向传播计算
    THFloatTensor* hidden = THFloatTensor_newWithSize1d(5);
    THFloatTensor_addmm(hidden, bias1, input, weights1);
    THFloatTensor_cadd(hidden, hidden, 1, bias1, 1);  // 加上偏置
    THFloatTensor_relu(hidden, hidden);  // 使用ReLU激活函数

    // 计算输出
    THFloatTensor* output = THFloatTensor_newWithSize1d(1);
    THFloatTensor_addmm(output, bias2, hidden, weights2);

    // 打印输出
    for (int i = 0; i < output->size[0]; ++i) {
        std::cout << THFloatTensor_get1d(output, i) << " ";
    }

    // 释放内存
    THFloatTensor_free(input);
    THFloatTensor_free(weights1);
    THFloatTensor_free(bias1);
    THFloatTensor_free(weights2);
    THFloatTensor_free(bias2);
    THFloatTensor_free(hidden);
    THFloatTensor_free(output);

    return 0;
}
