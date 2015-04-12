// isr.h -- Interface and structures for high level interrupt service routines.

#ifndef ISR_H
#define ISR_H

#include "common.h"

// A few defines to make life a little easier
#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

typedef struct {
	u32int ds; // Data segment selector
	u32int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
	u32int intNo, errCode; // Interrupt number and error code (if applicable)
	u32int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers;

// Enables registration of callbacks for interrupts or IRQs.
// For IRQs, to ease confusion, use the #defines above as the
// first parameter.
typedef void(*isrT)(registers);
typedef u32int (*isr2T)(u32int);
void registerInterruptHandler(u8int n, isrT handler);
void registerInterruptHandler2(u8int n, isr2T handler);

#endif // ISR_H