//into:
class CPythonPlayer : public CSingleton<CPythonPlayer>, public IAbstractPlayer
{
	public:

//add:
#ifdef PET_AUTODROP
		void SetPetAutoPickup(bool enable);
		bool HasPetAutoPickup() const;
#endif

//before:
		std::map<DWORD, DWORD> m_kMap_dwAffectIndexToSkillIndex;

//add:
#ifdef PET_AUTODROP
		bool m_bPetAutoPickup;
#endif

//it is how it has to looks like:
	private:
#ifdef PET_AUTODROP
		bool m_bPetAutoPickup;
#endif
		std::map<DWORD, DWORD> m_kMap_dwAffectIndexToSkillIndex;