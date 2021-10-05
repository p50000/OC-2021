#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *Realloc(void *ptr, size_t size)
{
	if (ptr == NULL) 
    {
        malloc(size);
    }
	if (!size)
    {
		free(ptr);
		return NULL;
	}
	void* ans = memcpy(malloc(size), ptr, size);
	return ans;
}

int main() 
{
   Realloc(NULL, 4);
}