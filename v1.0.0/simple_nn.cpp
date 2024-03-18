#include <torch/torch.h>

// 定义一个简单的神经网络
struct Net : torch::nn::Module {
    Net() {
        // 定义神经网络结构
        fc1 = register_module("fc1", torch::nn::Linear(784, 64));
        fc2 = register_module("fc2", torch::nn::Linear(64, 10));
    }

    // 前向传播函数
    torch::Tensor forward(torch::Tensor x) {
        x = torch::relu(fc1->forward(x.view({x.size(0), 784})));
        x = fc2->forward(x);
        return x;
    }

    torch::nn::Linear fc1{nullptr}, fc2{nullptr};
};

int main() {
    // 创建神经网络实例
    Net net;

    // 设置设备类型
    torch::Device device(torch::kCPU);

    // 创建一个随机输入张量
    auto inputs = torch::randn({5, 784}, device);

    // 将输入张量传递给神经网络获取输出
    auto outputs = net.forward(inputs);

    std::cout << "Output Tensor: " << outputs << std::endl;

    return 0;
}

