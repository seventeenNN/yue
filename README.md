# GPIO

## 什么是GPIO

GPIO 是通用输入输出（General Purpose Input/Output）的缩写。它是一种在微控制器或微处理器上常见的硬件接口，允许用户通过编程来控制和读取数字信号。

GPIO引脚可以配置为多种模式，以适应不同的应用需求。

**输入模式（Input Mode）：**

```
    浮空输入（Floating Input）：GPIO 引脚对外部电路呈现高阻抗状态，用于读取外部设备的状态。

    上拉（Pull-Up）：通过内部上拉电阻将 GPIO 引脚拉高到高电平，适用于按钮等设备。

    下拉（Pull-Down）：通过内部下拉电阻将 GPIO 引脚拉低到低电平，适用于按钮等设备。
```

**输出模式（Output Mode）：**

```
    推挽输出（Push-Pull）：GPIO 引脚可以输出高电平或低电平，提供较强的驱动能力。

    开漏输出（Open-Drain）：GPIO 引脚只能输出低电平或高阻态，需要外部上拉电阻输出高电平。

```
**模拟模式（Analog Mode）：**

```
当 GPIO 引脚配置为模拟模式时，通常是针对模拟输入功能。

在这种模式下，GPIO 引脚的数字输入输出功能会被禁用，以便为模拟信号提供一个干净的信号路径。

虽然模拟模式通常指的是模拟输入,但该微控制器也支持模拟输出模式。

在这种模式下，GPIO 引脚可以通过 DAC 将数字信号转换为模拟信号。

```

**复用功能（Alternate Function）：**

```
常见的复用功能包括：
串行通信接口：UART（Universal Asynchronous Receiver/Transmitter）：用于异步串行通信。

            SPI（Serial Peripheral Interface）：用于同步串行通信。

            I2C（Inter-Integrated Circuit）：用于同步串行通信，支持多设备连接。

模拟功能：ADC（Analog-to-Digital Converter）：用于读取模拟信号并转换为数字信号。

          DAC（Digital-to-Analog Converter）：用于将数字信号转换为模拟信号。

定时器和 PWM：PWM（Pulse Width Modulation）：用于生成脉宽调制信号，常用于控制电机、LED 亮度等。

             定时器（Timer）：用于生成精确的时间延迟或周期性事件。

外部中断：配置 GPIO 引脚作为外部中断输入，用于检测外部事件并触发中断服务程序。

其他特殊功能：如 CAN 总线、USB 控制器、以太网控制器等。

```






# DMA
