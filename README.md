This patch will allow you use some pets for autopickup items & cheque. That update works using the summoning item's vnum, not the mob_proto one so. 
The logic use the summoning item socket2, when you summon a pet the socke2 of the summoning item switches from 0 to 1, in this moment HasActiveAutoPickupItem is triggered for return true.
In autopickup_item_list.txt must be one single vnum for line.
