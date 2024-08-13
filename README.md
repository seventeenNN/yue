# 复位

**复位（Reset**是电子设备和微控制器中一个重要的概念，它指的是将设备或系统恢复到初始状态或已知的默认状态的过程。这种操作通常会重新启动系统的硬件和软件，使其进入一个可预测的状态，准备好执行预期的功能。

### 复位的主要功能和目的

1. **初始化系统**:
   - 复位用于将微控制器或设备的寄存器、计数器和内存等硬件资源清零或设定为初始值，以确保系统从已知的状态开始运行。

2. **恢复系统稳定性**:
   - 当系统遇到错误、死机、或异常行为时，复位可以强制系统重新启动，从而恢复系统的正常运行。

3. **硬件初始化**:
   - 复位信号会触发硬件初始化过程，配置外设、设置时钟、初始化I/O引脚等，为应用程序运行提供准备。

4. **启动程序执行**:
   - 在复位之后，微控制器会从特定的复位向量地址开始执行程序，通常这是系统启动代码所在的位置。

### 复位的类型

1. **电源复位（Power-On Reset, POR）**:
   - 当系统第一次上电时，复位电路会产生一个复位信号，确保设备在电源达到稳定状态后才开始工作。

2. **外部复位（External Reset）**:
   - 通过外部引脚施加一个复位信号（通常是低电平）来触发系统复位。这种复位通常由外部按钮或外部复位电路产生。

3. **看门狗复位（Watchdog Reset）**:
   - 如果系统因故障未能在规定时间内响应，看门狗定时器会触发复位，以防止系统长时间处于无响应状态。

4. **软件复位（Software Reset）**:
   - 系统软件可以通过写入特定寄存器来触发复位，这种复位通常用于软件控制下的重启。

5. **欠压复位（Brown-Out Reset, BOR）**:
   - 当电源电压降到某个临界值以下时，系统会自动复位，以防止低电压状态下工作不稳定。

### 复位过程

- **复位信号触发**: 当某种复位条件满足（如上电、外部复位信号或软件复位命令），复位电路生成一个复位信号。
- **系统初始化**: 微控制器停止当前执行的指令，清除寄存器和内存中的数据，将系统各部分恢复到初始状态。
- **启动执行**: 系统从预定义的复位向量地址开始执行启动代码，通常包括设置时钟、初始化外设、配置I/O等操作。
- **正常运行**: 系统完成初始化后，开始执行主程序或进入正常运行模式。

### 复位的关键作用

- **系统可靠性**: 复位功能确保系统在上电或出现错误时可以重新启动，避免长时间停机或不可预测的行为。
- **安全性**: 复位可以防止系统在异常条件下运行，保护系统硬件和数据的完整性。
- **可控性**: 软件可以通过复位控制系统的启动和重新初始化过程，适应不同的运行模式和需求。

### 总结

复位是将系统恢复到初始状态的过程，是保证系统稳定性和可靠性的重要机制。在电子设备中，复位通常通过硬件信号或软件指令触发，系统在复位后重新初始化，进入正常运行状态。复位的正确应用有助于确保系统在各种条件下稳定运行，并为开发人员提供控制系统行为的手段。












# 时钟

### 时钟是什么

“时钟”（Clock）是一个非常重要的概念，它指的是一个周期性信号，用于同步系统中各个组件的操作。时钟信号通常是一个固定频率的方波，它决定了系统中各个操作的节奏和时间顺序。

时钟的基本特性
频率：时钟信号的频率是指每秒钟发生的周期数，单位是赫兹（Hz）。例如，1 GHz的时钟频率意味着每秒钟有10亿个周期。

周期：时钟信号的周期是指一个完整周期的时间长度，它是频率的倒数。例如，1 GHz的时钟频率对应的周期是1纳秒（ns）。

占空比：时钟信号的占空比是指高电平时间与整个周期时间的比值。通常，时钟信号的占空比是50%，即高电平时间和低电平时间各占一半。

### 为什么要有时钟

时钟（Clock）是一个至关重要的组件，它提供了一个基准时间信号，用于同步系统中各个组件的操作。以下是为什么需要有时钟的几个主要原因：

同步操作：时钟信号确保系统中的各个组件（如CPU、内存、外设等）在正确的时间点执行操作。没有时钟信号，这些组件可能无法同步工作，导致数据冲突和操作错误。

控制数据流：在数字电路中，时钟信号控制数据的传输和处理。例如，CPU在每个时钟周期内执行一条指令，内存则在时钟信号的控制下读取或写入数据。

性能优化：时钟频率决定了系统的操作速度。通过设置合适的时钟频率，可以优化系统的性能，使其在处理任务时更加高效。

节能管理：虽然时钟信号的持续运行会消耗电力，但在需要执行操作时开启时钟是必要的。现代系统通常采用动态频率调整（Dynamic Frequency Scaling, DFS）和时钟门控（Clock Gating）等技术，以在不需要时关闭或降低时钟频率，从而节省电力。

稳定性保障：正确的时钟配置有助于确保系统的稳定性。不正确的时钟设置可能导致系统运行不稳定或无法正常工作。

硬件保护：持续的高频操作可能导致硬件过热或损坏。通过在不需要时关闭时钟，可以保护硬件免受长时间高频操作的影响。

时间基准：在某些应用中，时钟信号还用于提供时间基准，例如在通信系统中用于同步数据传输，或在实时操作系统中用于任务调度。

它确保了系统中各个组件能够正确、高效且稳定地运行。时钟信号是同步各个组件操作的关键，对于系统的性能、稳定性和功耗管理至关重要。

### 为什么要配置不同的时钟

配置不同的时钟是为了满足多种需求和优化系统性能。以下是为什么要配置不同时钟的几个主要原因：

性能优化：不同的应用和任务可能需要不同的处理速度。通过配置不同的时钟频率，可以根据需求调整系统的性能，例如在进行高强度计算时提高时钟频率，而在待机或低负载时降低时钟频率。

节能管理：持续的高频操作会消耗大量电力。通过配置不同的时钟频率，可以在不需要高性能时降低时钟频率，从而节省电力，延长电池寿命，特别是在移动设备和嵌入式系统中尤为重要。

稳定性保障：某些硬件组件可能对时钟频率有特定的要求，过高或过低的时钟频率可能导致系统不稳定或无法正常工作。通过配置合适的时钟频率，可以确保系统的稳定性。

兼容性考虑：不同的硬件组件（如CPU、内存、外设等）可能支持不同的时钟频率。配置不同的时钟频率可以确保这些组件能够正确协同工作，避免兼容性问题。

多任务处理：在多任务操作系统中，不同的任务可能需要不同的时钟频率。通过配置不同的时钟，可以为不同的任务提供合适的时间基准，确保任务能够高效且有序地执行。

硬件保护：持续的高频操作可能导致硬件过热或损坏。通过配置不同的时钟频率，可以在不需要时降低时钟频率，减少硬件的负担，保护硬件免受损坏。

动态频率调整（DFS）：现代系统通常支持动态频率调整，即根据系统负载实时调整时钟频率。这种技术可以在保证性能的同时，最大限度地节省电力。

配置不同的时钟是为了根据不同的应用需求和系统状态，优化性能、节省电力、确保稳定性、提高兼容性、支持多任务处理以及保护硬件。通过灵活配置时钟，可以使系统更加高效、稳定和可靠。

### 为什么程序启动前要先开时钟

同步操作：时钟信号确保系统中的各个组件（如CPU、内存、外设等）在正确的时间点执行操作。没有时钟信号，这些组件可能无法同步工作，导致数据冲突和操作错误。

初始化顺序：在系统启动或复位时，需要按照特定的顺序初始化各个组件。开启时钟是这个初始化过程的一部分，确保所有组件在正确的时机开始工作。

性能优化：时钟频率决定了系统的操作速度。通过开启时钟并设置合适的频率，可以优化系统的性能，使其在处理任务时更加高效。

节能管理：虽然时钟信号的持续运行会消耗电力，但在需要执行操作时开启时钟是必要的。现代系统通常采用动态频率调整（Dynamic Frequency Scaling, DFS）和时钟门控（Clock Gating）等技术，以在不需要时关闭或降低时钟频率，从而节省电力。

稳定性保障：正确的时钟配置有助于确保系统的稳定性。不正确的时钟设置可能导致系统运行不稳定或无法正常工作。

硬件保护：持续的高频操作可能导致硬件过热或损坏。通过在不需要时关闭时钟，可以保护硬件免受长时间高频操作的影响。

开启时钟是为了确保电子设备和计算机系统能够正确、高效且稳定地运行。时钟信号是同步各个组件操作的关键，对于系统的性能、稳定性和功耗管理至关重要。在运行程序之前开启时钟，可以确保系统准备好执行指令，避免因时钟信号缺失而导致的问题。

### 为什么不一直开着时钟

不一直开着时钟（Clock）有以下几个主要原因：

节能：一直开启时钟会持续消耗电力，尤其是在移动设备和嵌入式系统中，节能是一个重要的考虑因素。在不执行操作时关闭或降低时钟频率可以显著减少功耗，延长电池寿命。

避免干扰：在某些情况下，如系统休眠或待机状态，不需要时钟信号一直运行。关闭时钟可以避免不必要的干扰，确保系统在需要时能够快速响应。

硬件保护：持续的高频操作可能导致硬件过热或损坏。通过在不需要时关闭时钟，可以保护硬件免受长时间高频操作的影响。

灵活性：根据不同的应用场景和需求，系统可能需要动态调整时钟频率。例如，在进行高强度计算时提高时钟频率，而在待机或低负载时降低时钟频率。

时钟门控（Clock Gating）：这是一种技术，通过在不需要时关闭某些组件的时钟信号，来减少功耗。这可以应用于特定的硬件模块或外设，当它们不活跃时，可以关闭它们的时钟以节省电力。

动态频率调整（Dynamic Frequency Scaling, DFS）：这是一种根据系统负载动态调整时钟频率的技术，以平衡性能和功耗。在低负载时降低时钟频率，可以显著减少功耗。

初始化顺序：在系统启动时，可能需要按照特定顺序开启时钟，确保各个组件正确初始化并同步工作。在启动完成后，可以根据需要调整时钟频率。

不一直开着时钟可以带来节能、保护硬件、提高系统灵活性和响应速度等好处。通过智能管理时钟信号，可以在确保系统性能的同时，最大限度地减少功耗和硬件负担。






## 时钟和晶振

晶振（Crystal Oscillator）：

晶振是一种电子元件，它利用晶体的压电效应来产生稳定的频率信号。晶体（通常是石英晶体）在受到电压作用时会产生机械振动，这种振动在特定频率下非常稳定，因此晶振可以提供精确的时钟信号。

晶振可以是外部的，也可以是内部的（集成在微控制器或芯片内部）。外部晶振通常需要配合外部电容来构成一个完整的振荡电路。

时钟（Clock）：

时钟是指在电子设备中用于同步各个部件操作的周期性信号。在数字电路中，时钟信号决定了数据处理的速度和时序。

时钟信号通常由晶振产生，晶振提供的稳定频率信号经过分频或倍频处理后，形成适合设备运行的时钟信号。

关系总结：

晶振是产生时钟信号的源头，它提供了基础的频率信号。

时钟信号是晶振产生的频率信号经过处理后的结果，用于同步和控制电子设备中的各个部件。

### 晶振和振荡器

晶振（Crystal Oscillator）：

晶振是一种利用晶体的压电效应来产生稳定频率信号的元件。晶体通常是石英晶体，它在受到电压作用时会产生机械振动，这种振动在特定频率下非常稳定。

晶振可以是单个晶体（无源晶振），也可以是包含晶体和有源电路的模块（有源晶振）。无源晶振需要外部电路（如放大器）来驱动，而有源晶振内部集成了驱动电路，可以直接输出稳定的频率信号。

振荡器（Oscillator）：

振荡器是一个更广泛的概念，它指的是任何能够产生周期性信号的电路或设备。振荡器可以是基于晶体的（如晶振），也可以是基于其他原理的，例如RC振荡器、LC振荡器等。

振荡器可以是简单的电路，也可以是复杂的模块。它们的主要功能是产生稳定的频率信号，用于同步和控制电子设备中的各个部件。

关系和区别：

晶振是振荡器的一种，它特指利用晶体来产生稳定频率信号的振荡器。

振荡器是一个更广泛的概念，包括所有能够产生周期性信号的电路或设备，而晶振是其中一种特定类型的振荡器。

### 有源晶振，无源晶振

1. 有源晶振（Active Crystal Oscillator）：
有源晶振通常指的是一个**完整的振荡器模块**，它内部集成了*晶体谐振器、振荡电路和必要的放大器*。有源晶振可以直接输出一个稳定的频率信号，不需要外部电路来启动或维持振荡。有源晶振的输出通常是方波信号，频率范围可以从几十kHz到几GHz。由于其内部集成了放大器，有源晶振的输出信号幅度通常比无源晶振更大，且稳定性更高。有源晶振的常见类型包括石英晶体振荡器（XO）、温度补偿晶体振荡器（TCXO）、电压控制晶体振荡器（VCXO）和恒温控制晶体振荡器（OCXO）。

2. 无源晶振（Passive Crystal Oscillator）：
无源晶振通常指的是**晶体谐振器本身**，它需要外部电路（如放大器、反馈电阻等）来启动和维持振荡。无源晶振本身不包含振荡电路，因此不能直接输出振荡信号。无源晶振通常与一个或多个外部元件（如电容、电阻）一起使用，构成一个完整的振荡电路。无源晶振的频率通常由晶体的物理尺寸和切割方式决定，常见的无源晶振频率范围从几kHz到几百MHz。无源晶振的优点是成本较低，但由于需要外部电路，设计和调试相对复杂。

总结来说，有源晶振是一个完整的振荡器模块，可以直接输出稳定的频率信号，而无源晶振是一个晶体谐振器，需要外部电路来产生振荡信号。选择有源晶振还是无源晶振取决于具体的应用需求、成本预算和设计复杂度。

### 内部晶振和外部晶振

内部晶振（Internal Crystal Oscillator）和外部晶振（External Crystal Oscillator）是电子设备中用于产生时钟信号的两种不同配置方式。**它们的主要区别在于晶振的位置和集成方式。**

**内部晶振（Internal Crystal Oscillator）：**

内部晶振是指晶振电路集成在芯片或微控制器内部的配置。这种晶振通常是一个RC振荡器（Resistor-Capacitor Oscillator）或一个集成的晶体振荡器。

内部晶振的优点是简化了外部电路设计，不需要外部晶体和电容，从而减少了电路板的复杂性和成本。

内部晶振的缺点是通常精度不如外部晶振高，且频率稳定性可能较差。因此，内部晶振通常用于对时钟精度要求不高的应用。

**外部晶振（External Crystal Oscillator）：**

外部晶振是指晶振电路位于芯片或微控制器外部，通常是一个外部晶体或陶瓷谐振器，配合两个外部电容构成一个完整的振荡电路。

外部晶振的优点是能够提供更高的频率精度和稳定性，因为外部晶体通常比内部晶振更精确。

外部晶振的缺点是需要外部元件，增加了电路板的复杂性和成本。

总结来说，内部晶振和外部晶振的选择取决于应用的具体需求。如果对时钟信号的精度和稳定性要求较高，通常会选择外部晶振；如果对成本和电路简化要求较高，且对时钟精度要求不高，则可以选择内部晶振。在微控制器（如STM32）中，通常既支持内部晶振（如HSI，High-Speed Internal），也支持外部晶振（如HSE，High-Speed External），用户可以根据实际应用需求进行选择。

区别在于连接方式，以及需不需要谐振电容

## 区分

**时钟，时钟源，振荡器，晶振，时间模块**

### Resonator，Oscillator

外部晶振（External Crystal Resonator共鸣器，共振器）：
   
晶体振荡器（Crystal Oscillator振荡器）

1. Resonator（谐振器）

定义: Resonator（谐振器）是一种元件或电路，用于在特定频率下产生机械或电气谐振。谐振器本身不产生振荡信号，而是依靠外部电路激发或使用。

*（振荡信号: 是指在电路中周期性变化的信号，可以是正弦波、方波、三角波等形式。振荡信号的频率决定了时钟信号的频率。）*


类型:

	石英晶体谐振器: 使用石英晶体的机械振动特性在特定频率下谐振，通常用作时钟电路中的稳定频率源。

	陶瓷谐振器: 使用压电陶瓷材料的谐振特性，频率精度和稳定性通常低于石英晶体，但成本更低，体积更小。

	LC 谐振器: 使用电感 (L) 和电容 (C) 产生电气谐振，常用于无线电频率应用。
	
特点:   **无源元件: 自身不产生信号，仅在特定频率下响应并产生谐振。**

依赖外部电路: 需要与其他电路配合才能形成振荡信号，例如与放大器或其他有源电路配合使用。

2. Oscillator（振荡器）

定义: Oscillator（振荡器）是一个电路或器件，能够独立产生稳定的周期性信号（如正弦波或方波）。振荡器通常使用谐振器（如石英晶体）来设定其输出频率。

类型:

	*晶体振荡器*: 使用石英晶体谐振器的高稳定性来产生固定频率的振荡信号，广泛用于精密时钟和通信设备。

	*RC 振荡器*: 使用电阻 (R) 和电容 (C) 产生振荡信号，结构简单，但频率稳定性相对较差。

	*LC 振荡器*: 使用电感 (L) 和电容 (C) 产生高频振荡，常用于无线电频段。

特点:   **有源电路: 包含放大器和反馈电路，能够自主产生振荡信号。**

输出信号: 直接输出稳定的时钟或载波信号，供系统或其他电路使用。

**联系**

谐振器是振荡器的一部分: 振荡器通常使用谐振器来设定其振荡频率。谐振器提供了振荡器的频率选择性，但需要放大器和反馈电路来维持和稳定振荡。

共同目标: 两者的目标都是生成稳定的频率信号。谐振器提供了频率基准，而振荡器则将这个基准转化为持续的振荡信号。

**区别**

功能:

谐振器: 自身不产生信号，只提供特定频率下的谐振响应。

振荡器: 生成稳定的周期性信号，并可以独立工作。

**结构:**

**谐振器: 通常是无源元件，如石英晶体或LC电路。**

**振荡器: 是有源电路，通常包含放大器、反馈网络以及可能包含的谐振器。**

应用场景:

谐振器: 用于需要稳定频率的振荡器电路中，提供频率基准。

振荡器: 用于时钟生成、信号调制、载波生成等应用，提供稳定的振荡信号。

总结

Resonator（谐振器） 是用于产生特定频率谐振的元件或电路，本身不产生信号。

Oscillator（振荡器） 是可以独立产生稳定周期性信号的电路，通常使用谐振器来设定其频率。

在实际应用中，振荡器是一个更复杂、更完整的电路，而谐振器是其核心频率确定部分。

**晶振一般指：石英晶体振荡器（Crystal Oscillator）** 是有源元件


**区分**

1. 有源晶振（Active Crystal Oscillator）

定义: 内部集成了振荡电路和石英晶体的振荡器。它能够直接输出稳定的时钟信号，不需要外部振荡电路。

应用: 广泛用于各种电子设备中，提供精确的时钟信号。

2. 无源晶振（Passive Crystal **Resonator**）

定义: 只有石英晶体本身，**没有内置的振荡电路**。需要外部电路（如微控制器内的振荡器电路）来启动和维持振荡。

应用: 通常用于成本敏感的应用，或作为已有电路的一部分。


3. 内部晶振（Internal Oscillator）

定义: 指**嵌入**在微控制器或处理器内部的振荡器电路。它通常提供系统时钟，省去外部振荡器的需要。

应用: 用于微控制器和处理器的时钟源，简化设计和减少外部元件。

4. 外部晶振（External Crystal Oscillator）

定义: **连接**到微控制器或处理器的外部振荡器模块。可以是**有源或无源**的，提供系统所需的时钟信号。

应用: 用于需要高精度时钟信号的场合，或者在需要与系统主振荡器匹配的情况下。

#### 总结

外部晶振和内部晶振之间的主要区别在于它们的物理位置、集成方式以及如何在系统中提供时钟信号。

在芯片内部设计时，通常不使用“无源晶振”的概念。内部振荡器通常包含所有必要的电路，以保证振荡的产生和稳定性。

内部晶振通常用于提供基本的时钟信号，适用于大多数应用。**如果需要更高精度的时钟信号，可能会选择外部晶振或外部时钟源。**

内部晶振的频率和稳定性可能会受到温度和电源波动的影响，但对于许多应用来说，它提供的精度是足够的。



## 介绍stm32时钟部分：

在STM32微控制器中，时钟系统是一个非常关键的部分，它负责为微控制器的各个模块提供同步信号。STM32的时钟系统通常包括以下几种时钟源：

1. **高速外部时钟（HSE，High-Speed External）**：
   - HSE通常是一个外部晶体振荡器或陶瓷谐振器，配合两个外部电容构成一个振荡电路。HSE可以提供较高的频率，通常为4-26 MHz，具体取决于所使用的晶体或谐振器。
   - HSE的优点是频率精度高，稳定性好，适用于对时钟精度要求较高的应用。

2. **高速内部时钟（HSI，High-Speed Internal）**：
   - HSI是STM32内部集成的RC振荡器，可以直接提供时钟信号，不需要外部晶体或谐振器。HSI的典型频率为16 MHz。
   - HSI的优点是成本低，电路设计简单，但频率精度和稳定性通常不如HSE。

3. **低速外部时钟（LSE，Low-Speed External）**：
   - LSE通常是一个32.768 kHz的外部晶体振荡器，用于提供低速、高精度的时钟信号，常用于实时时钟（RTC）和日历功能。
   - LSE的优点是频率稳定，适用于需要长时间计时和低功耗的应用。

4. **低速内部时钟（LSI，Low-Speed Internal）**：
   - LSI是STM32内部集成的RC振荡器，频率通常为32-40 kHz，用于提供低速时钟信号，常用于RTC和独立看门狗（IWDG）。
   - LSI的优点是成本低，电路设计简单，但频率精度和稳定性通常不如LSE。

STM32的时钟系统还包括时钟树（Clock Tree），它负责将上述时钟源分配到微控制器的各个模块。时钟树通常包括以下几个部分：

- **系统时钟（SYSCLK）**：微控制器的主时钟，可以由HSE、HSI或PLL（锁相环）产生。
- **AHB总线时钟（HCLK）**：用于微控制器的高速总线（AHB），通常是SYSCLK的分频。
- **APB1总线时钟（PCLK1）**：用于微控制器的低速外设总线（APB1），通常是HCLK的分频。
- **APB2总线时钟（PCLK2）**：用于微控制器的高速外设总线（APB2），通常是HCLK的分频。

通过配置时钟树，可以灵活地为微控制器的各个模块分配不同的时钟频率，以满足不同应用的需求。

### HSE

**无源晶振工作原理**

HSE（High-Speed External）无源晶振在 STM32 中通常指外部连接的石英晶体，它需要借助于微控制器内部的振荡电路才能产生稳定的时钟信号。以下是 HSE 无源晶振的工作原理：

1. 石英晶体的特性
 
石英晶体是一种无源元件，其本身不产生振荡信号。石英晶体具有压电效应，当施加电压时会产生机械振动，这种机械振动在特定频率下具有谐振特性，这个频率称为晶体的谐振频率。

3. 振荡电路

外部振荡电路: STM32 内部集成了振荡电路，这个电路包括一个反相放大器和两侧的负载电容。振荡电路与石英晶体一起工作，形成一个振荡器。
工作原理: 当电路通电时，放大器会对电路中的噪声或初始电压变化进行放大，通过石英晶体的谐振特性，这些放大后的信号被反馈到振荡电路中，并在石英晶体的谐振频率下形成一个稳定的振荡信号。

4. 负载电容

负载电容: 通常连接在石英晶体的两端，它们的作用是与晶体一起形成一个共振回路，从而帮助调节振荡频率，确保电路在晶体的谐振频率下稳定工作。这些电容的大小需要根据晶体的规格来选择，通常在 10pF 到 20pF 之间。

5. 启动与稳定

启动时间: 当电源接通时，振荡电路需要一定时间来达到稳定的振荡状态，这个时间称为启动时间（Start-up Time），它取决于晶体的质量、负载电容值以及振荡电路的设计。
稳定性: 一旦振荡电路进入稳定状态，它将生成一个频率非常稳定的时钟信号，该信号用于驱动 STM32 的主时钟系统或其他外设。

6. HSE 输入

连接方式: 石英晶体通常连接到 STM32 的 HSE_IN 和 HSE_OUT 引脚，HSE_OUT 引脚用于驱动外部振荡电路，HSE_IN 引脚用于接收反馈信号。

工作总结

石英晶体本身不振荡，需要外部振荡电路配合。

STM32 内部振荡电路利用石英晶体的谐振特性生成稳定的时钟信号。

负载电容帮助调节频率，确保稳定工作。

HSE 模块可以使用这个外部时钟源作为系统时钟，提供高精度的时钟信号。

HSE 的无源晶振是通过内部振荡电路和石英晶体的协作来工作的，形成一个稳定的时钟信号。








## 配置系统时钟，总线时钟

### HSE

```c
  RCC_CR  |= RCC_CR_HSEON;
	while(!(RCC_CR & RCC_CR_HSERDY ));
	RCC_CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
```

### HSI

```c
RCC_CR  |= RCC_CR_HSION;
while(!(RCC_CR & RCC_CR_HSIRDY ));
RCC_CFGR |= RCC_CFGR_SW_HSI;
while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
```

### 主PLL

```c
  RCC_CR  |= RCC_CR_HSEON;
	while((RCC_CR & RCC_CR_HSERDY )==0); 
	
	
	//使能电源接口时钟
  //RCC_APB1ENR |= RCC_APB1ENR_PWREN;


 // PWR_CR |= PWR_CR_VOS;

	
  // 配置AHB分频器
  RCC_CFGR |= AHB_PRESCALER ;

  // 配置APB1分频器
  RCC_CFGR |= APB1_PRESCALER ;

  // 配置APB2分频器
  RCC_CFGR |= APB2_PRESCALER ;
	
 	RCC_PLLCFGR |=PLL_M_HSE ;
		RCC_PLLCFGR |=PLL_N ;
		RCC_PLLCFGR |=PLL_P ;
		RCC_PLLCFGR |=PLL_Q ;	
		RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;		
 // RCC_PLLCFGR = (PLL_M_HSE << 0) | (PLL_N << 6) | (PLL_P << 16) | (PLL_Q << 24) | (RCC_PLLCFGR_PLLSRC);
 
 
  RCC_CR |=RCC_CR_PLLON ;
  while((RCC_CR & RCC_CR_PLLRDY ) == 0)	;
	
	/*为什么一定要加上这一行!!!!!!!!!!!!!!!!!!!!*/
	//Flash预取、指令缓存、数据缓存和等待状态
	FLASH_ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;

  RCC_CFGR |=RCC_CFGR_SW_PLL;
	while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

```

**M设为1**

在使用相位锁定环（PLL，Phase-Locked Loop）进行频率合成时，PLL的分频因子M通常用于将输入时钟信号（通常是外部晶振或内部振荡器提供的时钟信号）分频到一个更低的频率。分频到1 MHz的信号通常是为了满足PLL电路的锁相环路对输入频率的要求。以下是具体原因：

1. PLL 的工作原理

PLL 是一种电路，用于生成更高频率的时钟信号。它通过调整输出信号的相位，使其与输入参考信号的相位保持一致，来锁定输出频率。

PLL的输入通常需要一个稳定的时钟信号，该信号经过分频后用于与PLL的反馈信号进行相位比较。

2. 分频因子 M 的作用

分频因子 M: 用于将输入时钟信号分频，产生一个适合PLL内部处理的参考频率。这个参考频率通常较低，以便PLL电路能够有效处理和锁定信号。

分频到1 MHz的原因:


标准化频率: 1 MHz 是一个较为常见的频率，很多PLL设计中使用这个频率作为基准，以确保稳定性和设计的一致性。

兼容性: 1 MHz 的参考频率通常与内部电路的设计和工作频率范围兼容，既能确保电路的稳定性，又能优化功耗。

精度和平衡: 分频到1 MHz后，PLL可以更容易地生成各种高频时钟信号，同时保证较高的精度。这是因为PLL电路通常在这个频率范围内具有最佳的相位噪声特性和平衡能力。

3. 频率合成和倍频

倍频: 在分频后，PLL 会通过内部倍频因子将参考频率提升到所需的输出频率。例如，如果需要的输出频率为48 MHz，且输入频率经过分频M后得到1 MHz，那么倍频因子可以设置为48。

频率合成的灵活性: 通过调整分频因子 M 和倍频因子，可以灵活合成所需的频率，同时确保输入参考信号在PLL电路可处理的范围内。

4. 系统的兼容性和设计要求

系统要求: 设计PLL时，将输入时钟分频到1 MHz通常是为了兼顾性能、稳定性和功耗，同时满足系统的设计规范。

参考频率稳定性: 1 MHz的参考频率通常能保证PLL在合理的响应时间内锁定到所需的输出频率，提供稳定的时钟信号。

总结

PLL的分频因子 M 一般用于将输入时钟信号分频到1 MHz，这是为了确保PLL能够高效、稳定地工作。1 MHz作为参考频率，能够在保证精度的同时，兼顾系统的稳定性和设计的兼容性。这使得PLL可以通过倍频实现更高频率的时钟信号，适应不同的应用需求。




**!!!**

```c
FLASH_ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;
```

1. 系统时钟频率与Flash访问速度的匹配
在高系统时钟频率下，CPU的执行速度会显著提高，但Flash的访问速度相对较慢。为了确保CPU能够高效地访问Flash，需要进行以下优化：

预取缓冲区（Prefetch Buffer）：启用预取缓冲区可以提高Flash的读取速度。预取缓冲区在读取Flash数据时提前预取数据，减少等待时间，从而提高系统性能。

指令缓存（Instruction Cache）：启用指令缓存可以加速指令的读取和执行。指令缓存将频繁执行的指令存储在高速缓存中，减少从Flash读取指令的次数，提高CPU的执行效率。

数据缓存（Data Cache）：启用数据缓存可以加速数据的读取和写入。数据缓存将频繁访问的数据存储在高速缓存中，减少从Flash读取数据的次数，提高数据访问速度。

等待状态（Latency）：设置Flash访问的等待状态。在高系统时钟频率下，Flash访问需要更多的等待时间，以确保数据可靠读取。FLASH_ACR_LATENCY_5WS 表示设置5个等待状态，以适应更高的系统时钟频率。

2. 实验结果分析
没有优化Flash访问性能：在没有加上 FLASH_ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS; 这一句代码的情况下，PLL配置可能不成功，LED没有闪烁。这表明在高系统时钟频率下，Flash访问速度跟不上CPU的执行速度，导致系统不稳定或无法正常工作。

优化Flash访问性能：在加上这一句代码后，LED成功闪烁。这表明通过优化Flash访问性能，系统在高时钟频率下能够稳定运行，CPU能够高效地访问Flash，从而实现预期的功能。

**解释**

1. FLASH_ACR_PRFTEN
预取缓冲区使能（Prefetch Buffer Enable）：启用Flash预取缓冲区，可以提高Flash的读取速度。预取缓冲区在读取Flash数据时提前预取数据，减少等待时间，从而提高系统性能。

2. FLASH_ACR_ICEN
指令缓存使能（Instruction Cache Enable）：启用指令缓存，可以加速指令的读取和执行。指令缓存将频繁执行的指令存储在高速缓存中，减少从Flash读取指令的次数，提高CPU的执行效率。

3. FLASH_ACR_DCEN
数据缓存使能（Data Cache Enable）：启用数据缓存，可以加速数据的读取和写入。数据缓存将频繁访问的数据存储在高速缓存中，减少从Flash读取数据的次数，提高数据访问速度。

4. FLASH_ACR_LATENCY_5WS
等待状态（Latency）：设置Flash访问的等待状态。在高CPU时钟频率下，Flash访问需要更多的等待时间，以确保数据可靠读取。FLASH_ACR_LATENCY_5WS 表示设置5个等待状态，以适应更高的CPU时钟频率。

通俗解释
当CPU的时钟频率提高时，CPU的执行速度也会加快，但Flash的访问速度相对较慢。为了确保CPU能够高效地访问Flash，需要进行以下优化：

减少等待时间：通过启用预取缓冲区和设置适当的等待状态，减少CPU在访问Flash时的等待时间，提高系统性能。

加速指令和数据访问：通过启用指令缓存和数据缓存，减少从Flash读取指令和数据的次数，提高CPU的执行效率和数据访问速度。

通过这些优化措施，可以确保在高CPU时钟频率下，Flash的读取速度能够跟上CPU的访问速度，从而提高系统的整体性能和稳定性。

