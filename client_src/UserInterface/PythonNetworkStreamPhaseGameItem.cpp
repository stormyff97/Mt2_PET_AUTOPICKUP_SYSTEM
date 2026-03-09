//after includes add:
#ifdef PET_AUTODROP
#include "PythonPlayer.h"
#endif

//into--> bool CPythonNetworkStream::RecvItemOwnership()
    //after:
	CPythonItem::Instance().SetOwnership(p.dwVID, p.szName);

//add:
#ifdef PET_AUTODROP
	if (CPythonPlayer::Instance().HasPetAutoPickup())
	{
		const char* ownerName = nullptr;

		if (CPythonItem::Instance().GetOwnership(p.dwVID, &ownerName))
		{
			const char* myName = CPythonPlayer::Instance().GetName();

			if (ownerName && strcmp(ownerName, myName) == 0)
			{
				CPythonNetworkStream::Instance().SendItemPickUpPacket(p.dwVID);
			}
		}
	}
#endif
