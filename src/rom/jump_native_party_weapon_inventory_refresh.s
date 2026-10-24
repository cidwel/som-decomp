; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-party-weapon-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_three_party_weapon_records_and_rebuild_attributes = $4CB8

.segment "CODE"
.org $3842
jump_native_party_weapon_inventory_refresh:
    jmp refresh_three_party_weapon_records_and_rebuild_attributes
