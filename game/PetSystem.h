//search:	DWORD			GetSummonItemVID () { return m_dwSummonItemVID; }

//add:
#ifdef PET_AUTODROP
DWORD			GetSummonItemVnum() const { return m_dwSummonItemVnum; }
#endif


//search:	size_t		CountSummoned() const;

//add:
#ifdef PET_AUTODROP
	const TPetActorMap& GetPetMap() const { return m_petActorMap; }
#endif