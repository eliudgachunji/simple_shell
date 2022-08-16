#include "simple.h"

/**
 * handler - handles the ctrl-c signal
 * @h: signal received
 * Return: Nothing.
 */

void handler(int h)

{

(void)h;

write(1, "\n#cisfun$ ", 10);
}
