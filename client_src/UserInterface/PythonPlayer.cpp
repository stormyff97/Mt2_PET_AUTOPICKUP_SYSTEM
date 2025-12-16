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