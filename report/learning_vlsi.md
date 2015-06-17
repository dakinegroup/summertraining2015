#Visit to ...
On 13th June, 2015 we had visited ..... where we had small discussion and introduction to VLSI and its various opportunities in industry. We also discussed about the processors we come across in our daily life.    
If we see our past, nearly 20 years ago and compare it with present we come to know that number of transiters in an integrated circuit has increased and it will still increase in near future. If we talk about clock speed of a processor then it has also increased but in future there will be a point when the the clock speed will start decreasing due to increase in capacitive and inductive effects.

**TODO**

* outline of this document should be as following. You need to expand on them, use internet here, to find more and digest, relate and capture (No COPY PASTE, even if possible diagrams should also be redone yourself)
   * Agenda of visit
      * Overview of VLSI and an outlook of industry
      * Design to fabrication process
      * Tools
      * Various specializations
      * Software linkage
      * Latest innovations
   * once this report is done, share a link with Puneet, puneet@coverify.org, as a gesture of thanks for his time.

   * Content below need to be organized accordingly. Refer to the inline comments, for enhancing information.

##Introduction to VLSI
**VLSI** - Very Large Scale Integration. Many ICs had a limited funtion to perform. VLSI overcame it. It is the process of creating an IC by combining thousands of transistors into a single chip.  


  * **TODO** What is the density of chips, in number. Checkout graph that shows this trend and paste it here.

**HDL** - Hardware Descriptive Language. It is the language used to program the structure, design and operation of electronic circuits. It gives description of an electronic circuit that allows for analysis, simulation and testing of that circuit.  
   * **TODO** If I am not wrong, it was VHDL, which he said is obsolete and is now being replaced by Verilog. HDL seems is a generic term. Update your text keeping this in mind.

**VHDL** - VHSIC Hardware Description Language.  
It is a HDL which is used in design automation to describe the behavior and structure of system and circuit designs.

**Verilog** - It is a HDL used to model electronic systems. It is used for design and verification of digital circuits at RTL.
   * **TODO** Is it from Open Source, under which license. Get that link and add here.

**RTL**-Register Transfer Level. It is a design abstraction which models a  synchronous digital circuit in terms of the flow of digital signals between hardware registers, and the logical operations performed on those signals.  
It focuses on describing how the signal will flow in the circuit. It is used in logic design phase on IC design cycle.  
Both _VHDL_ and _Verilog_ implement register-transfer-level abstractions.  
Verilog is derived from C programming language whereas VHDL has its roots in Ada programming language.  
Verilog is case sensitive whereas VHDL is not case sensitive.  



**EAD or ECAD** - Electronic Design Automation. It is software tools for designing PCB and ICs.
   * **TODO** Write the name of the companies, which are pioneers here. Is there anything in open source here? What about ready to use modules?
   * **TODO** Get some links for silicon layout from internet and try to explain how they are organized. Refer to the basic elements i.e. Transistors, how they combine to form gates, flipflops. Buses (horizontal and vertical lines)

##Processor

**RISC** - Reduced Instruction Set Computing. 
 * Simplified instructions are used in RISC.  
 * It provides high performance.  
 * It uses fewer microprocessor cycles per instruction.
 * RISC have separate intructions of I/O and data processing.
 * ARM, Atmel AVR uses RICS.

**CISC** - Complex instruction set computing.
 * Complex instructions are used in CISC.
 * Single instruction can execute low level operation such as load from memory set.
 * Intel x86 processors uses CISC.
 * **TODO** he referred to that even today intel has RISC architecture, but not leaving the CISC instruction set

In RISC the amount of work done by a instruction is reduced as compared to CISC in which execution of a single instruction take many memory cycles. RICS uses less energy than CISC chips. Therefore these are used in mobile phones.

**TODO** it is not amount of work that is reduced, it is pipelining that helps it prefetch instructions and execute them in parallel, therefore reducing number of clock cycles it take for a processor to execute.


**Multicore Processor** - It is a single compnent with two or more processing units.  
In multicore they can run multiple instructions at same time which increases overall speed programs managable to parallel computing.  
I consumes less energy and give high performance.

**TODO** it consumes less energy as it operates at lower frequency (Checkout some numbers here)

**TODO** puneet referred to challenge of multicore w.r.t. CISC and RISC. It is easier done in RISC architecture. Work needs to be divided amongst cores and it has a conflict at hardware level, where it is expected to pre-fetch instructions, where the next set of instructions might have been delegated to different processor.. (Read more and write)

**Multithreading** - 
It is the ability of a CPU or a single core in a multicore processor to execute multiple processes.  
It aims to increase utilization of a ssingle core by using instruction level parallelism.

**TODO** Use some diagrams from your research to explain it more, above statements are not sufficient.

Multicore processors have replaced multithreading technique and they are also used in mobile phones. But Intel still uses multithreading in Multicore processors.

**TODO** above statement is vague. Expand it to specifics. Intel does have cores and has hyperthreading.. What do you want to say in above paragraph?


**TODO** Talk about challenge of latest technology, comparison with speed of light, wavelength and hence the play of inductances, capacitances, resistances of tracks itself at the silicon layer. Also, at such high frequencies the power consumed increases.

**TODO** Mention a reference to the trend of reduced frequencies and increased cores in this context as well.

**TODO** Above content is not sufficient. What I wanted is that you get an introduction as well as know a person who is expert in VLSI. It should help you gauge this domain and do some research.

**TODO** Further, this research should get documented to refer back, best to be here in report itself.

**TODO** I am looking for lot of self-driven work, with a hint of information. It needs to come out. Above information is not sufficient to come back and read. Please spend quality time on this subject.
