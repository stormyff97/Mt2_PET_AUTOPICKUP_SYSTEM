//after the includes add:
#ifdef PET_AUTODROP
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#endif

//into--> bool ITEM_MANAGER::Initialize(TItemTable * table, int size)
// search:
		item->SetProto(tableInfo);
	}

//add
#ifdef PET_AUTODROP
	LoadAutoPickupItemList();
#endif
// How look like:

		item->SetProto(tableInfo);
	}
#ifdef PET_AUTODROP
	LoadAutoPickupItemList();
#endif
	return true;
}


//into --> bool ITEM_MANAGER::CreateDropItem(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<LPITEM> & vec_item)

//after:
		DBManager::instance().SendMoneyLog(MONEY_LOG_DROP, item->GetVnum(), item->GetCount());
	}

//add
#ifdef PET_AUTODROP
	if (pkKiller && pkKiller->HasActiveAutoPickupItem())
	{
		for (LPITEM pItem : vec_item)
		{
			if (!pItem)
				continue;

			pkKiller->ChatPacket(
				CHAT_TYPE_INFO,
				LC_TEXT("Hai ricevuto: %s x%d"),
				pItem->GetName(),
				pItem->GetCount()
			);

			pkKiller->AutoGiveItem(pItem, true);
		}

		vec_item.clear();
	}
#endif


//add at the end of the file:

#ifdef PET_AUTODROP
std::set<DWORD> g_autoPickupItems;

void ITEM_MANAGER::LoadAutoPickupItemList()
{
	g_autoPickupItems.clear();

	std::ifstream file("locale/germany/autopickup_item_list.txt");
	if (!file.is_open())
	{
		sys_err("AutoPickup: cannot open autopickup_item_list.txt");
		return;
	}

	DWORD vnum;
	while (file >> vnum)
		g_autoPickupItems.insert(vnum);

	sys_log(0, "AutoPickup: loaded %zu items", g_autoPickupItems.size());
}
#endif