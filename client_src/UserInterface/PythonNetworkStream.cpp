// into--> 
	public:
		CMainPacketHeaderMap()
//add:
			Set(HEADER_GC_PET_AUTOPICKUP,			CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCPetAutoPickup), STATIC_SIZE_PACKET));

