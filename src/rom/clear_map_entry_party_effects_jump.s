; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_entry_party_effects_bridge = $3848

.segment "CODE"
.org $0060
clear_map_entry_party_effects_jump:
    jmp clear_map_entry_party_effects_bridge
