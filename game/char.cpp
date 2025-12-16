// add at the end of the file:
#ifdef PET_AUTODROP
void CHARACTER::SendPetAutoPickupState()
{
    if (!GetDesc())
        return;

    TPacketGCPetAutoPickup p;
    p.header = HEADER_GC_PET_AUTOPICKUP;
    p.enabled = HasActiveAutoPickupItem() ? 1 : 0;

    GetDesc()->Packet(&p, sizeof(p));
}
#endif