// #define K2_DEBUG_VERBOSE
#define K2_DEBUG_WARN

#include <stddef.h>
#include <stdint.h>

#include "plat.h"
#include "utils.h"
#include "sched.h"

extern void test_ktimer();     // unittests.c
extern void test_fb_voffset(); // unittests.c
extern void donut();           // donut.c
extern void donut_simple();    // donut.c
extern void donut_text();      // donut.c

void uart_send_string(char* str);

struct cpu cpus[NCPU]; 

void kernel_main() {
	// quest: UART. call uart_init() to initialize
	/* STUDENT_TODO: your code here */
	// quest: UART. init printf by init_printf(NULL, XXX)
	/* STUDENT_TODO: your code here */
	printf("------ kernel boot ------  core %d\n\r", cpuid());
	printf("build time (kernel.c) %s %s\n", __DATE__, __TIME__); // simplicity 

	sys_timer_init();                   // kernel timer: delay, timekeeping...
	enable_interrupt_controller(0);     // coreid
	// quest: sys_timer irq
	/* STUDENT_TODO: your code here */

	generic_timer_init();               // periodic ticks alive

	if (fb_init() != 0) BUG();          // will show the OS logo

	// test_ktimer();
	// test_fb_voffset();               // cycle through color quads
	/* STUDENT_TODO: your code here */

	// quest: pixel donut. call donut_simple()
	/* to enable it,  irq handler must be modified to call sys_timer_irq_simple() */
	/* STUDENT_TODO: your code here */
	
	// quest: textual donut. call donut_text()
	/* STUDENT_TODO: your code here */

	while (1)
		asm volatile("wfi");            // what happen here?
}