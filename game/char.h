//search: 		CPetSystem*			GetPetSystem()				{ return m_petSystem; }

//add afet:
#ifdef PET_AUTODROP
		const CPetSystem* GetPetSystem() const { return m_petSystem; }
#endif


//Into--> class CHARACTER : public CEntity, public CFSM, public CHorseRider
            //public:

#ifdef PET_AUTODROP
		bool HasActiveAutoPickupItem() const;
		void SendPetAutoPickupState();
#endif