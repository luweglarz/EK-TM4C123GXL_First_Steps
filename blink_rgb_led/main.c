#include <stdint.h>

// System control base address
# define SYSCTL_BASE ((volatile uint32_t) 0x400FE000)
// GPIO Run Mode Clock Gating Control offset
# define RCGCGPIO ((volatile uint32_t) 0x608)
// GPIO Advanced High-Performance Bus Control (AHB) offset
# define GPIOHBCTL ((volatile uint32_t) 0x06C)

// Address of the RCGCGPIO 
# define PORTF_CLOCK *((volatile uint32_t *) (SYSCTL_BASE + RCGCGPIO))
// Address of the GPIOHBCTL
# define PORTF_AHB *((volatile uint32_t *) (SYSCTL_BASE + GPIOHBCTL))

// GPIO Port F base address for APB
# define PORTF_APB_BASE ((volatile uint32_t) 0x40025000)
// GPIO Port F base address for AHB
# define PORTF_AHB_BASE ((volatile uint32_t) 0x4005D000)
// GPIO Digital enable offset
# define GPIODEN ((volatile uint32_t) 0x51C)
// GPIO Direction I/O offset
# define GPIODIR ((volatile uint32_t) 0x400)
// GPIO Data offset for pin 1,2,3 see page 662 and 654 of the data sheet for more informations about GPIODATA
# define GPIODATA ((volatile uint32_t) 0x38)

// Address of the Port F Digital Enable
# define PORTF_DEN *((volatile uint32_t *) (PORTF_AHB_BASE + GPIODEN))
// Address of the Port F Direction
# define PORTF_DIR *((volatile uint32_t *) (PORTF_AHB_BASE + GPIODIR))
// Address of the Port F Data
# define PORTF_DATA *((volatile uint32_t *) (PORTF_AHB_BASE + GPIODATA))

int main(void)
{
	// Set the the 6th bit to 1 to enable and provide a clock to GPIO PORT F in Run mode.
	PORTF_CLOCK = 0x20;

	/// Set the the 6th bit to 1 to enable AHB to GPIO PORT F.
	PORTF_AHB = 0x20;

	// Set the 2nd bit to 1 to enable GPIO Digital on the pin1 (PF1) corresponding to red light of the port F
	PORTF_DEN = 0x02;

	// Set the 2nd bit to 1 to enable GPIO Direction on the pin1 (PF1) corresponding to red light of the port F
	PORTF_DIR = 0x02;

	// Set the 2nd bit to 1 to enable GPIO Data on the pin1 (PF1) corresponding to red light of the port F
	PORTF_DATA = 0x02;
}

