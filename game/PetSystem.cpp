//into --> void CPetActor::Unsummon(
    //before the last }

//add:
#ifdef PET_AUTODROP
    if (m_pkOwner)
        m_pkOwner->SendPetAutoPickupState();
#endif

//into--> DWORD CPetActor::Summon(const char* petName, LPITEM pSummonItem, bool bSpawnFar)
    //after:
	m_pkChar->Show(m_pkOwner->GetMapIndex(), x, y, z);
//add:
#ifdef PET_AUTODROP
    m_pkOwner->SendPetAutoPickupState();
#endif