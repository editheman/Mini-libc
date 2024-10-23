// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *d;

	for (d = destination; *source != '\0'; source++, d++)
		*d = *source;
	*d = *source;

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *d;

	for (d = destination; *source != '\0' && len != 0; source++, d++, len--)
		*d = *source;
	while(len != 0){
		*d = '\0';
		d++;
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *d;
	for (d = destination + strlen(destination); *source != '\0'; source++, d++)
		*d = *source;
	*d = *source;

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *d;
	for (d = destination + strlen(destination); *source != '\0' && len != 0; source++, d++, len--)
		*d = *source;
	*d = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if(strlen(str1) > strlen(str2))
		return 1;
	else if (strlen(str1) < strlen(str2))
			return -1;
	for(size_t i = 0; i < strlen(str1); i++)
		if(str1[i] - str2[i] != 0)
			return str1[i]-str2[i];
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	if(strlen(str1) < len || strlen(str2) < len)
		return -1;
	for(size_t i = 0 ; i < len ; i++)
		if(str1[i] - str2[i] != 0)
			return str1[i]-str2[i];
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (size_t i = 0 ; i <= strlen(str) ; i++)
		if(str[i] == (char)c)
			return (char *)(str+i);
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int index = -1;
	for (size_t i = 0 ; i <= strlen(str) ; i++)
		if(str[i] == (char)c)
			index = i;
	if(index != -1)
		return (char *)(str+index);
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if(strlen(haystack) < strlen(needle))
		return NULL;
	for(size_t i = 0 ; i <= strlen(haystack) ; i++){
		size_t k = 0;
		if(haystack[i] == needle[0]){
			for(size_t j = i ; k <= strlen(needle) && j <= strlen(haystack) ; k++, j++)
				if(haystack[j] != needle[k])
					break;
			if(k == strlen(needle))
				return (char *)haystack + i;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if(strlen(haystack) < strlen(needle))
		return NULL;
	int index = -1;
	for(size_t i = 0 ; i <= strlen(haystack) ; i++){
		size_t k = 0;
		if(haystack[i] == needle[0]){
			for(size_t j = i ; k <= strlen(needle) && j <= strlen(haystack) ; k++, j++)
				if(haystack[j] != needle[k])
					break;
			if(k == strlen(needle))
				index = i;
		}
	}
	if(index != -1)
		return (char *)haystack + index;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	for (size_t i = 0 ; i < num ; i++)
		dest[i] = src[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;

	if(dest + strlen(dest) < src || dest > src + strlen(src))
		memcpy(dest, src, num);
	else
	{
		for (int i = num; i > 0 ; i--)
			dest[i - 1] = src[i - 1];
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *ptr_aux1 = (char *)ptr1;
	char *ptr_aux2 = (char *)ptr2;

	for(size_t i = 0 ; i < num ; i++)
		if(ptr_aux1[i] - ptr_aux2[i] != 0)
			return ptr_aux1[i] - ptr_aux2[i];
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for(size_t i = 0 ; i < num ; i++)
		src[i] = value;
	return source;
}
