/*
 * fifo.h
 *
 *  Created on: 5. dets 2016
 *      Author: madis
 */

#ifndef FIFO_H_
#define FIFO_H_

typedef struct {
     char *buf;
     int head;
     int tail;
     int size;
} fifo_t;

void fifo_init(fifo_t *f, int size);
int fifo_read(fifo_t * f, char *buf, int nbytes);
int fifo_write(fifo_t *f, const char buf);

#endif /* FIFO_H_ */
