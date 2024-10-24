// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p = NULL;
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	mem_list_init();
	if(p == NULL)
		return NULL;
	mem_list_add(p, size);
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p;
	p = malloc(nmemb*size);
	if(p == NULL)
		return NULL;
	memset(p, 0, nmemb*size);
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *elem;
	elem = mem_list_find(ptr);
	if(elem == NULL)
		return;
	munmap(elem->next, elem->len);
	mem_list_del(elem->start);
	mem_list_cleanup();
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    struct mem_list *elem = mem_list_find(ptr);
    if (elem == NULL) {
        return NULL;
    }
    void *new_ptr = mremap(ptr, elem->len, size, 0);
    if (new_ptr == MAP_FAILED) {
        return NULL;
    }
    if (new_ptr != ptr) {
        mem_list_del(ptr);
        mem_list_add(new_ptr, size);
    } else {
        elem->len = size;
    }
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return realloc(ptr, nmemb*size);
}
