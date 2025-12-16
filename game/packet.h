//add it to the GC header list (for example after HEADER_GC_DS_TABLE)
#ifdef PET_AUTODROP
	HEADER_GC_PET_AUTOPICKUP 					= 219,  //choose the correct value for you, be sure about no duplicates
#endif

//search:
} TPacketGCItemShop;

//add after:
#ifdef PET_AUTODROP
typedef struct SPacketGCPetAutoPickup
{
    BYTE header;
    BYTE enabled;
} TPacketGCPetAutoPickup;
#endif