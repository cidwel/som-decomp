; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_map_graphics = $DFD3

.segment "CODE"
.org $DFCF
load_actor_map_graphics_entry:
    jsr load_actor_map_graphics
    rtl
