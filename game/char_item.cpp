// search--> void CHARACTER::AutoGiveItem(LPITEM item, bool longOwnerShip)

//change like this

void CHARACTER::AutoGiveItem(LPITEM item, bool longOwnerShip)
{
	if (NULL == item)
	{
		sys_err("NULL point.");
		return;
	}
	if (item->GetOwner())
	{
		sys_err("item %d 's owner exists!", item->GetID());
		return;
	}

#ifdef PET_AUTODROP
	if (item->IsStackable() && !IS_SET(item->GetAntiFlag(), ITEM_ANTIFLAG_STACK))
	{
		for (int i = 0; i < INVENTORY_MAX_NUM; ++i)
		{
			LPITEM invItem = GetInventoryItem(i);
			if (!invItem)
				continue;

			if (invItem->GetVnum() != item->GetVnum())
				continue;

			// controllo socket
			bool sameSocket = true;
			for (int j = 0; j < ITEM_SOCKET_MAX_NUM; ++j)
			{
				if (invItem->GetSocket(j) != item->GetSocket(j))
				{
					sameSocket = false;
					break;
				}
			}
			if (!sameSocket)
				continue;

			int canAdd = 200 - invItem->GetCount();
			if (canAdd <= 0)
				continue;

			int toAdd = MIN(canAdd, item->GetCount());

			invItem->SetCount(invItem->GetCount() + toAdd);
			item->SetCount(item->GetCount() - toAdd);

			if (item->GetCount() == 0)
			{
				LogManager::instance().ItemLog(this, invItem, "AUTOPICKUP_STACK", invItem->GetName());
				M2_DESTROY_ITEM(item);
				return;
			}
		}
	}

	int cell = GetEmptyInventoryEx(item);
	if (cell != -1)
	{
		item->AddToCharacter(this, TItemPos(item->GetWindowInventoryEx(), cell));
		LogManager::instance().ItemLog(this, item, "AUTOPICKUP", item->GetName());

		if (item->GetType() == ITEM_USE && item->GetSubType() == USE_POTION)
		{
			TQuickslot* pSlot;
			if (GetQuickslot(0, &pSlot) && pSlot->type == QUICKSLOT_TYPE_NONE)
			{
				TQuickslot slot;
				slot.type = QUICKSLOT_TYPE_ITEM;
				slot.pos = cell;
				SetQuickslot(0, slot);
			}
		}
		return;
	}
	item->AddToGround(GetMapIndex(), GetXYZ());

#ifdef ENABLE_NEWSTUFF
	item->StartDestroyEvent(g_aiItemDestroyTime[ITEM_DESTROY_TIME_AUTOGIVE]);
#else
	item->StartDestroyEvent();
#endif

	item->SetOwnership(this, longOwnerShip ? 300 : 60);
	LogManager::instance().ItemLog(this, item, "AUTOPICKUP_DROP", item->GetName());

#else

	int cell = GetEmptyInventoryEx(item);
	if (cell != -1)
	{
		item->AddToCharacter(this, TItemPos(item->GetWindowInventoryEx(), cell));

		LogManager::instance().ItemLog(this, item, "SYSTEM", item->GetName());

		if (item->GetType() == ITEM_USE && item->GetSubType() == USE_POTION)
		{
			TQuickslot* pSlot;

			if (GetQuickslot(0, &pSlot) && pSlot->type == QUICKSLOT_TYPE_NONE)
			{
				TQuickslot slot;
				slot.type = QUICKSLOT_TYPE_ITEM;
				slot.pos = cell;
				SetQuickslot(0, slot);
			}
		}
	}
	else
	{
		item->AddToGround(GetMapIndex(), GetXYZ());

#ifdef ENABLE_NEWSTUFF
		item->StartDestroyEvent(g_aiItemDestroyTime[ITEM_DESTROY_TIME_AUTOGIVE]);
#else
		item->StartDestroyEvent();
#endif

		item->SetOwnership(this, longOwnerShip ? 300 : 60);
		LogManager::instance().ItemLog(this, item, "SYSTEM_DROP", item->GetName());
	}
#endif
}


//add it at bottom-file:

#ifdef PET_AUTODROP
bool CHARACTER::HasActiveAutoPickupItem() const
{
	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)
	{
		LPITEM item = GetInventoryItem(i);
		if (!item)
			continue;

		// il vnum deve essere nella lista autopick
		if (!g_autoPickupItems.count(item->GetVnum()))
			continue;

		// SIGILLO PET ATTIVO (socket 2)
		if (item->GetSocket(2) != 0)
			return true;
	}

	return false;
}
#endif


//into--> bool CHARACTER::PickupItem(DWORD dwVID)
	//after:
		if (item->IsOwnership(this))
		{

//add:
		#ifdef PET_AUTODROP
			// Pet auto-pickup: blocca item NON stackabili se inventario pieno
			if (HasActiveAutoPickupItem())
			{
				if (!item->IsStackable())
				{
					if (GetEmptyInventoryEx(item) == -1)
					{
						ChatPacket(CHAT_TYPE_INFO, LC_TEXT("PET: Inventory full!"));
						return false;
					}
				}
			}
		#endif
