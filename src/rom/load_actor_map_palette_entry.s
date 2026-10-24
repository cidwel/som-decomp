; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_map_palette = $E022

.segment "CODE"
.org $E01E
load_actor_map_palette_entry:
    jsr load_actor_map_palette
    rtl
