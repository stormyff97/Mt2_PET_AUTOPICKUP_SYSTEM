//search:
			case HEADER_GC_ITEM_GROUND_ADD:

//add after break; 
#ifdef PET_AUTODROP
			case HEADER_GC_PET_AUTOPICKUP:
				ret = RecvPetAutoPickup();
				break;
#endif

//add to the bottom of the file:
#ifdef PET_AUTODROP
bool CPythonNetworkStream::RecvPetAutoPickup()
{
	TPacketGCPetAutoPickup p;
	if (!Recv(sizeof(p), &p))
		return false;

	CPythonPlayer::Instance().SetPetAutoPickup(p.enabled != 0);
	return true;
}
#endif