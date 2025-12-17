//add these functions where you want:
#ifdef PET_AUTODROP
void CPythonPlayer::SetPetAutoPickup(bool enable)
{
	m_bPetAutoPickup = enable;
}
bool CPythonPlayer::HasPetAutoPickup() const
{
	return m_bPetAutoPickup;
}
#endif

//into--> void CPythonPlayer::Clear()
	//search:
	m_inGuildAreaID = 0xffffffff;

//add after:
#ifdef PET_AUTODROP
	m_bPetAutoPickup = false;
#endif
