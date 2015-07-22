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

k- méthode createRequete(hasmap)
- methode sendRequest(string requete) : renvoie le résultat
-analyse de la requête() : renvoyer la requête dans une des méthodes : insert, select... en fonction du premier arguement

#include "MyNoSql.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_hashmap {
	double load_factor; //taux de remplissage max
	double growth_factor; //taux d’expension longue load factor atteint
	unsigned int initial_slots; //taille initiale de tableau
	unsigned int slots; //taille actuelle du tableau
	Unsigned int size; //nb entrées dans la map
	t_hashmap_entry** entries; //le tableau
} t_hashmap ;

void hash_map_display(t_hashmap map)
{
    unsigned int i =O;
    t_hashmap_entry* tmp;
    while(i<map->slots)
    {
        tmp = map->entries[i];
        
        while(tmp!=null)
        {
            printf("%s -> %s\n", tmp->key, tmp->value);
            tmp = tmp->next;
        }
        
        i++;
    }
}

t_hashmap * hashmap_create(unsigned int slots, double load_float, double growth_factor)
//initialiser la structure et affecter NULL à toutes les valeurs du tableau entries
{
	t_hashmap * map = (t_hashmap)malloc(sizeof(t_hashmap));
	map->load_float = load_float;
	map->growth_factor = growth_factor;
	
	int i;
	
	for(i=0; i<slots; i++)
	{
		map->entries[i] = NULL;
	}
	
	return map;
}


t_hashmap_entry * hashmap_entry_create(char* key, void* value)
{
	t_hashmap_entry * entry = (t_hashmap *)malloc(sizeof(t_hashmap_entry);
	
	entry->value = value;
	entry->key = key;
	entry->next = NULL;
	
	return entry;
}

void hashmap_put(t_hashmap * map, char* key, void* value)
{
	if(map->size >= map->slots*map->load_float)
	{
		//hashmap_expand(map);
	}
	
	unsigned int hash = hashmap_hash(key, map->slot);
	unsigned int short found = 0;
	t_hashmap_entry ** entry =&(map->entry[hash]);
	
	while(*entry)
	{
		if(0 == strcmp(key, (*entry)->key))
		{
			(*entry)->value = value;
			found = 1;
			break;
		}
		entry =&(*entry)->next;
	}
	
	if(!found)
	{
		map->size++;
		*entry = hashmap_create_entry(key, value);
	}
}

void hashmap_remove(t_hashmap * map, char* key)
{
	unsigned int hash = hashmap_hash(key, map->slot);
	t_hashmap_entry * tmp;
	t_hashmap_entry** entry =&map->entry[hash];
	
	while(*entry)
	{
		if(!strcmp(key, (*entry)->key))
		{
			tmp = *entry;
			*entry = (*entry)->next;
			free(tmp);
			map->size--;
			break;
		}
		entry =&(*entry)->next;
	}
}

void * hashmap_get(t_hashmap * map, char* key)
{
	unsigned int hash = hashmap_hash(key, map->slot);
	t_hashmap_entry * entry = map->entry[hash];
	
	while(entry)
	{
		if(!strcmp(key, entry->key))
			return entry->value;
		entry = entry->next;
	}
	
	return NULL;
}

t_hashmap_keys * hasmap_key(t_hashmap * map)
{
	int i;
    int keyCount = 0;
    t_hashmap_entry* entry_set;
    t_hashmap_keys* hk = (t_hashmap_keys*)malloc(sizeof(t_hashmap_keys));
    hk->keys = (char**)malloc(sizeof(char*)*map->size);
    
    for(i=0; i<map->slots; i++)
    {
        entry_set = map->entries[i];
        
        while(entry_set)
        {
            hk->key[key_count] = strcpy(entry_set[key]);
            key_count++;
            hk->length = key_count;
            entry_set = entry_set->next;
        }
    }
    
    return hk;
}

void hashmap_expand(t_hashmap * map)
{
	unsigned int i = map->slot;
	t_hashmap_entry ** entry = map->entry;
	
	map->slot *= map->growth_factor;
	map->size = 0;
	map->entry = (t_hashmap_entry**)calloc(map->slot, sizeof(t_hashmap_entry*));
	t_hashmap_entry * prev, * element;
	
	while(i--) //parcours de la liste contigue
	{
		element = entry[i];
		while(element) //parcours de la liste chainee
		{
			hashmap_put(map, element->key, element->value);
			// recopie l'élement
			prev = element;
			element = element->next;
			
			free(prev); //libère l'élement de l'ancienne liste chainée
		}
	}
	free(entry); //libère l'ancienne liste contigue
}

unsigned int hashmap_hash(char* key, int slots)
{
	unsigned int hash = 1063;
	while(*key)
			hash += *(key++);
	return hash%slot;
}

//switch case des ordres
if(order == 'insert'){
	m_insert(value);
}
else if(order == 'set'){
	m_set(value);
}
else if(order == 'remove'){
	m_remove(value);
}
else if(order == 'get'){
	m_get(value);
}
else if(order == 'where'){
	m_where(value);
}
else if(order == 'find'){
	m_find(value);
}
else if(order == 'projection'){
	m_projection(value);
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

