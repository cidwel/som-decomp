; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_entry_party_effects = $5D46

.segment "CODE"
.org $3848
clear_map_entry_party_effects_bridge:
    jmp clear_map_entry_party_effects
