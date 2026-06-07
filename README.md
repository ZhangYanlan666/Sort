# Sort
C++ 轻量级排序算法库，实现冒泡排序、选择排序，支持泛型 + 自定义比较器，无任何第三方依赖。

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++ Version](https://img.shields.io/badge/C++-11+-brightgreen.svg)](https://en.cppreference.com/)

## 目录
- [项目介绍](#项目介绍)
- [快速开始](#快速开始)
  - [环境要求](#环境要求)
  - [安装步骤](#安装步骤)
  - [运行示例](#运行示例)
- [核心功能](#核心功能)
- [使用文档](#使用文档)
  - [默认排序（升序）](#默认排序升序)
  - [自定义比较器](#自定义比较器)
  - [接口详细说明](#接口详细说明)
- [贡献指南](#贡献指南)
- [许可证](#许可证)

## 项目介绍
本项目是纯原生 C++ 编写的基础排序算法库，无需依赖任何第三方库、标准库扩展或外部工具，代码简洁、结构清晰，专为学习、练习与小型项目使用设计。

库中实现了两种最经典的排序算法：冒泡排序和选择排序，并通过模板技术支持任意可比较数据类型（int、double、结构体等）。
所有排序函数均将“默认升序”与“自定义比较规则”合并为统一接口，使用手写函数作为默认比较器，不使用结构体、不使用 STL 比较器。

项目特点：
- 轻量、简洁、无依赖
- 模板泛型，支持任意类型
- 单一函数实现默认排序 + 自定义规则
- 比较器使用普通函数，易于理解
- 适合 C++ 算法入门学习

## 快速开始
### 环境要求
- 支持 C++11 及以上标准的编译器
- Visual Studio 2019 / 2022（项目提供 .slnx 工程）
- 无任何外部依赖，无需配置环境，开箱即用

### 安装步骤
1. 克隆或下载本项目到本地
git clone https://github.com/你的用户名/Sort.git

2. 打开文件夹，双击 Sort.slnx 启动 Visual Studio 项目
3. 直接点击“生成”与“运行”即可编译执行
4. 若要在自己项目中使用，只需复制 sort.h 到项目中并引用

### 运行示例
#include "sort.h"
#include <iostream>
using namespace std;

int main() {
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);

    // 默认升序排序
    sort::bubbleSort(arr, len);

    cout << "排序结果：";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

运行后输出：
1 2 3 4 5 6 9

## 核心功能
1. **冒泡排序**
   - 支持默认从小到大排序
   - 支持传入自定义比较函数
   - 模板支持任意数据类型

2. **选择排序**
   - 支持默认从小到大排序
   - 支持自定义比较规则
   - 效率稳定，逻辑清晰

3. **通用交换工具函数**
   - 模板实现，可交换任意两个同类型变量

4. **默认比较函数**
   - 纯手写函数实现升序规则
   - 不依赖任何库、不使用结构体
   - 可被自定义比较器覆盖

## 使用文档
### 默认排序（升序）
不传比较器时，所有算法默认从小到大排序：

sort::bubbleSort(arr, len);
sort::selectionSort(arr, len);

### 自定义比较器
你可以传入自己的比较函数，实现降序、自定义规则等：

bool myCompare(int a, int b) {
    return a < b; // 实现从大到小排序
}

sort::bubbleSort(arr, len, myCompare);

比较器规则：
cmp(a, b) 返回 true 表示 a 应该放在 b 后面。

### 接口详细说明
#### 1. 交换函数
template<typename T>
void Swap(T& a, T& b);

交换两个变量的值，内部使用。

#### 2. 默认比较函数
template<typename T>
bool defaultCompare(const T& a, const T& b);

默认升序规则：a > b 时返回 true，表示需要交换。

#### 3. 冒泡排序（合并版）
template<typename T, typename Compare>
void bubbleSort(T* arr, int len, Compare cmp = defaultCompare<T>);

- T：任意可比较类型
- arr：数组指针
- len：数组长度
- cmp：可选，自定义比较函数

#### 4. 选择排序（合并版）
template<typename T, typename Compare>
void selectionSort(T* arr, int len, Compare cmp = defaultCompare<T>);

使用方式与冒泡排序完全一致。

## 贡献指南
欢迎提交 Issue 与 Pull Request 来改进本项目！

贡献步骤：
1. Fork 本项目
2. 创建你自己的功能分支
3. 修改或新增代码
4. 提交并推送
5. 创建 Pull Request

## 许可证
本项目基于 MIT 开源许可证，你可以自由使用、修改、分发，包括商业用途。
详细内容请查看 LICENSE.txt 文件。
