//add to the GC headers list:
#ifdef PET_AUTODROP
	HEADER_GC_PET_AUTOPICKUP					= 219,  //be sure this number matches the one into packet.h serversid
#endif


//after:
} TPacketGCItemShop;
#endif

//add:
#ifdef PET_AUTODROP
typedef struct SPacketGCPetAutoPickup
{
	BYTE header;
	BYTE enabled;
} TPacketGCPetAutoPickup;
#endif