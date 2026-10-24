; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-party-weapon-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

jump_native_party_weapon_inventory_refresh = $3842

.segment "CODE"
.org $005A
jump_public_party_weapon_inventory_refresh:
    jmp jump_native_party_weapon_inventory_refresh
