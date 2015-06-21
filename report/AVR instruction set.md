##Operational Instructions
By these instructions we can perform various operations like addition , multiplication and subtraction.  
Various instructions for addition are :-  
 1. **ADC**- It adds two registers with carry flag and put value in the destination register.
 2. **ADD**- It adds two registers and put final value in the destination register.
 3. **ADIW**- It adds immediate value to register pair and places the result in register pair.d={24,26,28,30}                        k=0-63;

Various instructions for multiplication are :-
 1. **MUL**- It multiplies two unsigned numbers contained in Rd and Rr. R1:R0=Rd*Rr. Where R1 is contains MSB and R0 contains LSB.  
 2. **MULS**-It multiply two signed numbers in Rd and Rr.
 3. **MULSU**- Multiply signed with unsigned. In this Rd is signed and Rr is unsigned number. d=16-23   r=16-23

Various instructions for subtraction are :-
 1. **SBC**
 2. **SBCI**
 3. **SBIW**
 4. **SUB**
 5. **SUBI**  
 _**NOTE**_-_In all these instructions the all are subtracted from number present in Rd and then the resultant numbers are stored in Rd._    

##Logical Instructions
These are the instructions through with logical operations are performed like OR, AND etc.  Some of them are:-
 1. **AND** – Performs logical AND b/w contents of Rd and Rr and resultant is stored in Rd.
 2. **ANDI**- Logical and with immediate. It performs AND b/w contents of Rd and Constant K. d=16-23      K=0-255
 3. **OR and ORI** – Performs logical OR between Rd and Rr and Rd and constant K respectively. For ORI d=16-23      K=0-255.
 4. **EOR** – Exclusive OR.  

##SET Instructions
 1. **SEC** – Set carry Flag. C<-1. After this command we can use ADC or SBC or SBCI.
 2. **SEH** – Sets Half Carry flag. H<-1.
 3. **SEI** – Sets global interrupt. I<-1.  
  **SEN , SES , SET , SEV , SEZ** are other set commands in which _Negative flag, signed flag , T flag, overflow flag_ respectively are set.  
_**NOTE**_-These flags are there in SREG.
 4. **SBI** – Sets bit in I/O register.
 5. **SBR** – Sets bits in Register. Rd<-Rd v K.  


 
 






 










 
 



