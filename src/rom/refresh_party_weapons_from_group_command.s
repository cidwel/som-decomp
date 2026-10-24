; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-weapon-command.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_party_weapon_inventory_refresh = $C0005A
routine_c1ebd4 = $EBD4

.segment "CODE"
.org $EBCB
refresh_party_weapons_from_group_command:
    .a8
    cmp #$0C
    bcs routine_c1ebd4
    jsl f:jump_public_party_weapon_inventory_refresh
    rts
