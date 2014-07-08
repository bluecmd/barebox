#include <common.h>
#include <init.h>
#include <driver.h>
#include <partition.h>
#include <ns16550.h>

static struct NS16550_plat serial_plat = {
	.clock = OPENRISC_SOPC_UART_FREQ,
	.shift = 0,
};

static int openrisc_console_init(void)
{
	barebox_set_model("Mexiko");
	barebox_set_hostname("mexiko");

	/* Register the serial port */
	add_ns16550_device(DEVICE_ID_DYNAMIC, OPENRISC_SOPC_UART_BASE, 1024,
			   IORESOURCE_MEM | IORESOURCE_MEM_8BIT, &serial_plat);

	add_generic_device("ethoc", DEVICE_ID_DYNAMIC, NULL,
			   OPENRISC_SOPC_ETHOC_BASE, 0x1000,
			   IORESOURCE_MEM, NULL);

	return 0;
}

console_initcall(openrisc_console_init);
