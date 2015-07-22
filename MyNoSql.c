/*	BDD moisi
---------------------------

creer un parseur pour les delimiteur
creer un convertisseur utilisant parseur pour passer du format json a la query an CL
ORDRES = get , insert , set , remove , createBase , createTable , where , find , projection
*/
-recuperer les arguments (après les tirets)
-execution ordre par ordre (for)
-scinder en deux parties les arguments, premier order , second order_value
-selon l'ordre -> action ( if else multiple)

#include "MyNoSql.h"
#include <stdio.h>
#include <stdlib.h>


tab_order_entry* order_entry_create(char* order, void* value){
	tab_order_entry* entry = (tab_order*)malloc(sizeof(tab_order_entry);
	
	entry->value = value;
	entry->order = order;
	entry->next = NULL;
	
	return entry;
}

void add_order(tab_order* map, char* order, void* value){
	unsigned int short found = 0;
	tab_order_entry** entry = &(map->entry[order]);
	
	while(*entry){
		// si l'entrée n'existe pas encore
		if(strcmp(order, (*entry)->order) == 0){
			//associe la value
			(*entry)->value = value;
			found = 1;
			break;
		}
		entry =&(*entry)->next;
	}
	
	if(!found){
		*entry = order_entry_create(order, value);
	}
}

void* get_order(tab_order* map, char* order){
	unsigned int hash = order_hash(order, map->slot);
	tab_order_entry* entry = map->entry[hash];
	
	while(entry){
		if(!strcmp(order, entry->order))
			return entry->value;
		entry = entry->next;
	}
	
	return NULL;
}

main(int argc, char** argv){

//char* tab_order_entry[argc];

	// recupération des arguments
	for(a=0; a<argc; a++){	
		char* temp = argv[a];
		for(b=0; b<*(temp->lenght+1); b++){
			//recuperation de l'ordre
			if(temp[0] == '-'){
				order[b+1] = temp[b+1];
			}
			//recuperation de la valeur
			if(temp[b+1] == '="'){
				value[b+2] = temp[b+2];
			}
		}
		for()(
		*order_tab[a] = *argv[a];
		
	
	}


}