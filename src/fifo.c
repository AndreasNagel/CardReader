/*
 * fifo.c
 *
 *  Created on: 5. dets 2016
 *      Author: Andreas Nagel
 */

#include "fifo.h"
#include <stdlib.h>




void fifo_init(fifo_t *f, int size){
     f->head = 0;
     f->tail = 0;
     f->size = size;
     f->buf = (char*)malloc(size*sizeof(char));
}

/* Input: *f - a pointer to a fifo element from which read is performed
 * 		  *buf - char pointer where read bytes are saved (output of read
 * 		  nbytes - number of bytes to be read by the function
 * Description: The function reads the number of bytes designated from a fifo element.
 *              The function return the number of bytes read by it. The buffer given
 *              as an input needs to be big enough to fit the bytes read. I.e 8 bytes are read, then buffer has to be char[8]
 */
int fifo_read(fifo_t * f, char *buf, int nbytes){
     int i;
     char *p;
     p = buf;
     for(i=0; i < nbytes; i++){
          if(f->tail != f->head ){ //see if any data is available
               *p++ = f->buf[f->tail];  //grab a byte from the buffer
               f->tail++;  //increment the tail
               if(f->tail == f->size){  //check for wrap-around
                    f->tail = 0;
               }
          } else {
        	   for(i; i>=0; i--){
        		   if(f->tail == 0){
        			   f->tail = size;
        		   }
        		   f->tail--;
        	   }
               return 0; //number of bytes read
          }
     }
     return nbytes;
}


/*	Input: *f - a pointer to a fifo element where to write
 * 		   *buf - a byte to be written
 *  Description: The function writes one byte to a fifo element
 */
int fifo_write(fifo_t *f, const char buf){
	//Check to if there is space in the buffer
	if((f->head + 1 == f->tail) || ((f->head + 1 == f->size) && (f->tail == 0))){
		return 0; // fifo is full
	} else {
	   f->buf[f->head] = buf;
	   f->head++;                 //increment the head
	   if( f->head == f->size ){  //check for wrap-around
			f->head = 0;
	   }
	}
    return 1;
}
