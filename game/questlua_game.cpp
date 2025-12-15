//into 	ALUA(game_drop_item_with_ownership)
    //search:		if (lua_isnumber(L, 3))

//add before:
	#ifdef PET_AUTODROP
		if (ch->HasActiveAutoPickupItem())
		{
			ch->ChatPacket(
				CHAT_TYPE_INFO,
				LC_TEXT("Hai ricevuto: %s x%d"),
				item->GetName(),
				item->GetCount()
			);

			ch->AutoGiveItem(item, true);
			return 0;
		}
	#endif