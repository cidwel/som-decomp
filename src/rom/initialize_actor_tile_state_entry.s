; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_actor_tile_state = $DF37

.segment "CODE"
.org $DF22
initialize_actor_tile_state_entry:
    jsr initialize_actor_tile_state
    rtl
