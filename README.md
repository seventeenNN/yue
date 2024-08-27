# 中断

## 中断执行流程

1. 中断触发

中断源产生事件：当一个外设或外部信号（如定时器溢出、GPIO引脚变化、通信接口接收数据等）产生事件时，触发中断信号。

中断请求（IRQ）信号：中断源通过中断请求线（IRQ）向中断控制器发送中断信号。此时，中断控制器检测到有中断请求。

2. 中断响应

中断控制器（NVIC）响应中断：嵌入式系统中通常有嵌套向量中断控制器（NVIC）来处理中断。NVIC会检查中断是否使能以及优先级是否高于当前正在执行的任务或中断。如果是，它会向处理器发出中断请求。

中断屏蔽检查：如果中断使能且没有被屏蔽，处理器会停止当前的任务，保存当前任务的上下文（包括程序计数器、状态寄存器等）。

3. 处理器中断向量跳转

中断向量表查找：处理器根据中断号在中断向量表中查找对应的中断服务例程（ISR）的地址。中断向量表是一个存储不同中断服务例程入口地址的表，每个中断号对应一个固定的位置。

跳转到中断服务例程（ISR）：处理器加载中断服务例程的起始地址并跳转到相应的中断处理函数。

4. 中断处理

中断服务例程执行：处理器开始执行中断服务例程（ISR），ISR 负责处理中断事件，比如读取外设数据、清除中断标志位、执行必要的计算或逻辑操作。

优先级处理：如果系统允许嵌套中断，并且当前中断的优先级低于某些可能发生的中断，处理器在执行当前 ISR 的过程中可能会被更高优先级的中断打断，并处理更高优先级的中断。

5. 中断结束与恢复

清除中断标志：在 ISR 中，中断标志位（或中断请求寄存器的相应位）需要被清除，以便系统能够继续响应未来的中断请求。

恢复上下文：处理器在完成 ISR 之后，需要恢复先前保存的任务上下文。具体而言，处理器将恢复被中断时的程序计数器和状态寄存器的值。

返回主程序：处理器从中断返回指令 RETI 或者 BX LR（针对 ARM Cortex-M 处理器）中恢复，并返回到主程序的被中断位置，继续执行主程序。

6. 嵌套中断（可选）

中断嵌套：如果系统允许中断嵌套，则在处理一个中断的过程中，如果有更高优先级的中断触发，处理器会暂停当前的 ISR 并转而处理更高优先级的中断。处理完高优先级中断后，处理器会返回到被中断的 ISR 并继续处理。
。

### 中断向量表中的中断的地址代表什么含义

**中断服务例程的入口地址：** 中断向量表中的每个地址都是一个内存地址，指向相应中断服务例程（ISR）的第一条指令。

**中断处理的起始点：** 当处理器响应一个中断时，它会自动跳转到中断向量表中对应的地址，从那里开始执行中断处理代码。

**中断优先级和处理顺序：** 中断向量表中的地址顺序通常反映了中断的优先级，高优先级的中断通常位于表的较低位置。

**系统初始化和异常处理：** 除了中断处理程序，中断向量表还可能包含系统初始化代码（如复位处理程序）和异常处理程序（如硬故障、总线故障等）的入口地址。


# IWDG

独立看门狗:独立看门狗用通俗一点的话来解释就是一个 12 位的递减计数器，当计数器的值从某个值一直减到 0的时候，系统就会产生一个复位信号，即IWDG RESET。
如果在计数没减到 0之前，刷新了计数器的值的话，那么就不会产生复位信号，这个动作就是我们经常说的喂狗。
看门狗功能由 VDD 电压域供电，在停止模式和待机模式下仍能工作。

看门狗定时器是一种硬件计时器，用于监控系统的运行状态。如果系统出现故障或软件运行异常，
导致无法定期“喂狗”（即重置看门狗定时器），看门狗定时器会在超时后触发复位信号，从而重启系统，以恢复正常运行。

# USART
