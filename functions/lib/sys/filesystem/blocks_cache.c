
/*
 *
 * Operating System Design / Diseño de Sistemas Operativos
 * (c) ARCOS.INF.UC3M.ES
 *
 * @file 	blocks_cache.c
 * @brief 	This file contains the definition of the functions that must be used in
 *              order to read or read to and from the device.
 * @date	Last revision 01/04/2020
 *
 */


#include "filesystem/blocks_cache.h"


/****************/
/* Disk access. */
/****************/

/*
 * Reads a block from the device and stores it in a buffer.
 * Returns 0 or -1 in case of error, including short
 * read.
 */
int bread(char *deviceName, int blockNumber, char *buffer) {
	int fd = open(deviceName, O_RDONLY);

	if(fd < 0){
		/* fprintf(stderr, "ERROR: UNABLE TO OPEN DISK FILE %s \n", deviceName); */
		return -1;
	}

	int len = lseek(fd, 0, SEEK_END) + 1;
	if((BLOCK_SIZE*blockNumber+BLOCK_SIZE) > len) {
		close(fd);
		return -1;
	}

	lseek(fd, BLOCK_SIZE*blockNumber, SEEK_SET);

	int total_read, read_result;

	total_read = 0;
	do{
		read_result = read(fd, buffer+total_read, BLOCK_SIZE-total_read);
		total_read = total_read + read_result;
	} while(total_read < BLOCK_SIZE && read_result >= 0);

	close(fd);

	return 0;
}

/*
 * Writes a block from a buffer to the device.
 * Returns 0 or -1 in case of error.
 */
int bwrite(char *deviceName, int blockNumber, char*buffer) {
	int fd = open(deviceName, O_WRONLY);

	if(fd < 0){
		/* fprintf(stderr, "ERROR: UNABLE TO OPEN DISK FILE %s \n", deviceName); */
		return -1;
	}

	int len = lseek(fd, 0, SEEK_END) + 1;
	if((BLOCK_SIZE*blockNumber+BLOCK_SIZE) > len) {
		close(fd);
		return -1;
	}

	lseek(fd, BLOCK_SIZE*blockNumber, SEEK_SET);

	int total_write, write_result;

	total_write = 0;
	do{
		write_result = write(fd, buffer+total_write, BLOCK_SIZE-total_write);
		total_write = total_write + write_result;
	} while(total_write < BLOCK_SIZE && write_result >= 0);

	close(fd);

	return 0;
}
