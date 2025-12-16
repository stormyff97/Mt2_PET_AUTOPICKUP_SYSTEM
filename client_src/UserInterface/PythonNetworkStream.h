//after:
		bool RecvTargetDeletePacket();


//add:
#ifdef PET_AUTODROP
		bool RecvPetAutoPickup();
#endif