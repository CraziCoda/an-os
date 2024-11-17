#ifndef IO_H
#define IO_H
/**
 *  Sends given data to given I/O port. Definded io.s
 * 
 * @param port The I/O port to send data to
 * @param data The data to send to the I/O port
 * @returns void
 */
void outb(unsigned short port, unsigned char data);

#endif