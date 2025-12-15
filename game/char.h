//Into--> class CHARACTER : public CEntity, public CFSM, public CHorseRider
            //public:

#ifdef PET_AUTODROP
		const CPetSystem* GetPetSystem() const { return m_petSystem; }
		bool HasActiveAutoPickupItem() const;
#endif