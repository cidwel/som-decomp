; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_boss_resources_from_cache = $0040

.segment "CODE"
.org $0000
initialize_boss_resources_public_jump:
    jmp initialize_boss_resources_from_cache
