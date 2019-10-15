#ifndef IRCHARSEND_H
#define IRCHARSEND_H

/* Send character choice to rival board and set choice sent flag high */
int send_character(char choice);

/* Retrieve character choice from rival board as char*/
char recieve_character(void);

#endif
