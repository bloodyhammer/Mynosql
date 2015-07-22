#include <stdio.h>
#include <stdlib.h>

typedef struct s_hashmap_entry {
	char* key;
	void* value;
	struct s_hashmap_entry* next;
} t_hashmap_entry;

typedef struct hashmap_keys {
	char* keys;
	unsigned int length;
} t_hashmap_keys;


t_hashmap * hashmap_create(unsigned int slots, double load_float, double growth_factor);
t_hashmap_entry * hashmap_entry_create(char* key, void* value);
t_hashmap_keys * hasmap_key(t_hashmap * map);

void hash_map_display(t_hashmap map);
void hashmap_put(t_hashmap * map, char* key, void* value);
void hashmap_remove(t_hashmap * map, char* key);
void * hashmap_get(t_hashmap * map, char* key);
void hashmap_expand(t_hashmap * map);

unsigned int hashmap_hash(char* key, int slots);



void m_insert(value);
void m_set(value);
void m_get(value);
void m_remove(value);
void m_where(value);
void m_find(value);
void m_projection(value);
