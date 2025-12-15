//after includes:
#ifdef PET_AUTODROP
#include <set>
extern std::set<DWORD> g_autoPickupItems;
#endif


//after 		virtual ~ITEM_MANAGER();

//add:
#ifdef PET_AUTODROP
		void LoadAutoPickupItemList();
#endif