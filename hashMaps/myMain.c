/* DO NOT SUBMIT */
 
#include "hashMap.h"
#include <stdio.h>
 
 
int main()
{
     
 
    /* Test 1 */
    // HashMap* hashMapNew(int capacity);
    // void hashMapDelete(HashMap* map);
    // printf("Test 1: Create and destroy map without memory leak.\n");
    // HashMap *map1 = hashMapNew(10);
    // hashMapDelete(map1);
    // printf("Test 1 functions written to check: hashMapCleanup\n\n");
 
    // /* Test 2 */
    // printf("Test 2: Add to map, then clean up. Tests if cleanup gets link.\n");
 
    // HashMap *map2 = hashMapNew(10);
    // hashMapPrint(map2);
    // hashMapPut(map2, "sarah", 2);
    // hashMapPrint(map2);
    // hashMapDelete(map2);
    // printf("Test 2 functions written to check: hashMapPut, hashMapCleanup\n\n");
 
    // /* Test 3 */
    // printf("Test 3: Add to map, update, then clean up. Tests if value updated.\n");
    // HashMap *map3 = hashMapNew(10);
    // hashMapPrint(map3);
    // hashMapPut(map3, "sarah", 2);
    // hashMapPut(map3, "sarah", 4);
    // hashMapPrint(map3);
    // hashMapDelete(map3);
    // printf("Test 3 functions written to check: hashMapPut, hashMapCleanup\n\n");
 
    // /* Test 4 */
    // printf("Test 4: Add two to map, then clean up. Tests if works with mult. values.\n");
    // HashMap *map4 = hashMapNew(10);
    // hashMapPrint(map4);
    // hashMapPut(map4, "sarah", 2);
    // hashMapPut(map4, "seth", 4);
    // hashMapPrint(map4);
    // hashMapDelete(map4);
    // printf("Test 4 functions written to check: hashMapPut, hashMapCleanup\n\n");
 
    // /* Test 5 */
    // printf("Test 5: Add two to map, then test hashMapGet.\n");
    // HashMap *map5 = hashMapNew(10);
    // hashMapPrint(map5);
    // hashMapPut(map5, "sarah", 2);
    // hashMapPut(map5, "seth", 4);
    // printf("Address of sarah->: %p\n", hashMapGet(map5, "sarah"));
    // printf("Address of seth->: %p\n", hashMapGet(map5, "seth"));
    // printf("Address of shane->: %p\n", hashMapGet(map5, "shane"));
    // hashMapPrint(map5);
    // hashMapDelete(map5);
    // printf("Test 5 functions written to check: hashMapGet, hashMapCleanup\n\n");
 
    // /* Test 6 */
    // printf("Test 6: Add two to map, then test hashMapRemove.\n");
    // HashMap *map6 = hashMapNew(10);
    // hashMapPrint(map6);
    // hashMapPut(map6, "sarah", 2);
    // hashMapPut(map6, "seth", 4);
    // hashMapPrint(map6);
    // hashMapRemove(map6, "seth");
    // hashMapPrint(map6);
    // hashMapDelete(map6);
    // printf("Test 6 functions written to check: hashMapRemove, hashMapCleanup\n\n");
 
    // /* Test 7 */
    // printf("Test 7: Add two to map, then test hashMapContainsKey.\n");
    // HashMap *map7 = hashMapNew(10);
    // hashMapPrint(map7);
    // hashMapPut(map7, "sarah", 2);
    // hashMapPut(map7, "seth", 4);
    // hashMapPrint(map7);
 
    // printf("Contains seth: %d\n", hashMapContainsKey(map7, "seth"));
    // hashMapRemove(map7, "seth");
    // printf("Contains seth: %d\n", hashMapContainsKey(map7, "seth"));
 
    // printf("Contains sarah: %d\n", hashMapContainsKey(map7, "sarah"));
    // printf("Contains shane: %d\n", hashMapContainsKey(map7, "shane"));
 
    // hashMapPrint(map7);
    // hashMapDelete(map7);
    // printf("Test 7 functions written to check: hashMapContainsKey, hashMapRemove\n\n");
 
    // /* Test 8 */
    // printf("Test 8: Add two to map, then test hashMapEmptyBuckets.\n");
    // HashMap *map8 = hashMapNew(10);
    // printf("Empty Buckets: %d\n", hashMapEmptyBuckets(map8));
    // hashMapPrint(map8);
    // hashMapPut(map8, "sarah", 2);
    // printf("Empty Buckets: %d\n", hashMapEmptyBuckets(map8));
    // hashMapPut(map8, "seth", 4);
    // printf("Empty Buckets: %d\n", hashMapEmptyBuckets(map8));
    // hashMapPrint(map8);
 
    // hashMapRemove(map8, "seth");
    // printf("Empty Buckets: %d\n", hashMapEmptyBuckets(map8));
    // hashMapRemove(map8, "sarah");
 
    // printf("Empty Buckets: %d\n", hashMapEmptyBuckets(map8));
 
    // hashMapPrint(map8);
    // hashMapDelete(map8);
    // printf("Test 8 functions written to check: hashMapEmptyBuckets, hashMapRemove\n\n");
    // /* This is where you should enable resize and run again. */
 
    // /* Test 9 */
    // printf("Test 9: Add many to map to test resizeTable.\n");
    // HashMap *map9 = hashMapNew(10);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "ab", 1);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "cd", 2);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "ef", 3);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "gh", 4);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "ij", 5);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "kl", 6);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "mn", 7);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "op", 8);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "qr", 9);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "st", 10);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "uv", 11);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "wx", 12);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapPut(map9, "yz", 13);
    // printf("Capacity: %d\n", hashMapCapacity(map9));
    // printf("Size: %d\n", hashMapCapacity(map9));
    // hashMapPrint(map9);
    // hashMapDelete(map9);
    // printf("Test 9 functions written to check: resizeTable, hashMapRemove\n\n");
    /* All functions */
    // HashMap* hashMapNew(int capacity); 
    // hashMapDelete(map);
    // int* hashMapGet(HashMap* map, const char* key);
    // void hashMapPut(HashMap* map, const char* key, int value);
    // void hashMapRemove(HashMap* map, const char* key);
    // int hashMapContainsKey(HashMap* map, const char* key);
 
    // int hashMapSize(HashMap* map);
    // int hashMapCapacity(HashMap* map);
    // int hashMapEmptyBuckets(HashMap* map);
    // float hashMapTableLoad(HashMap* map);
    // void hashMapPrint(HashMap* map);
 
    return 0;
}