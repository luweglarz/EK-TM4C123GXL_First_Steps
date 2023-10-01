/*
	0x400FE000 is the System Control base Address
	0x608 is the Offset for the PORTF
*/
# define PORTFCLOCK *((volatile unsigned long *) (0x400FE000 + 0x608))
/*
	0x40025000 is the starting address of PORTF GPIO
	0x51C is the Offset for the GPIO Digital Enable
*/
# define GPIODEN *((volatile unsigned long *) (0x40025000 + 0x51C))
/*
	0x40025000 is the starting address of PORTF GPIO
	0x400 is the Offset for the GPIO direction
*/
# define GPIODIR *((volatile unsigned long *) (0x40025000 + 0x400))
/*
	0x40025000 is the starting address of PORTF GPIO
	0x0x8 is the Offset for the pin1 (PF1) data address see page 662 and 654 of the data sheet for more information on how data register works

*/
# define GPIODATA *((volatile unsigned long *) (0x40025000 + 0x08))

int main(void)
{
	// Set the the 6th bit to 1 to enable and provide a clock to GPIO PORT F in Run mode.
	PORTFCLOCK = 0x20;

	// Set the 2nd bit to 1 to enable GPIO Digital on the pin1 (PF1)
	GPIODEN = 0x02;

	// Set the 2nd bit to 1 to enable GPIO Direction on the pin1 (PF1) 
	GPIODIR = 0x02;

	//PORTF DATA ADDR
	//volatile unsigned long *GPIODATA = ((volatile unsigned long *)0x40025000 + 0x38);

	GPIODATA = 0x02;
}

