// into--> void CHARACTER::RewardGold(LPCHARACTER pkAttacker)
    //search: 
	bool isAutoLoot =
		(pkAttacker->GetPremiumRemainSeconds(PREMIUM_AUTOLOOT) > 0 ||
		 pkAttacker->IsEquipUniqueGroup(UNIQUE_GROUP_AUTOLOOT)
		)

//change like this:
	bool isAutoLoot =
		(pkAttacker->GetPremiumRemainSeconds(PREMIUM_AUTOLOOT) > 0 ||
		 pkAttacker->IsEquipUniqueGroup(UNIQUE_GROUP_AUTOLOOT)
#ifdef PET_AUTODROP_YANG
		 || pkAttacker->HasActiveAutoPickupItem()
#endif
		)
        