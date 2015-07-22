#include <stdio.h>
#include <stdlib.h>

typedef struct struct_order_entry {
	char* order;
	void* value;
	struct struct_order_entry* next;
} tab_order_entry;

tab_order_entry* order_entry_create(char* order, void* value);

void add_order(tab_order* map, char* order, void* value);
void* get_order(tab_order* map, char* order);

 