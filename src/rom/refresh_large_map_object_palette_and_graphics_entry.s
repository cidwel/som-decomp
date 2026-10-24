; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0df48 = $DF48

.segment "CODE"
.org $DF51
refresh_large_map_object_palette_and_graphics_entry:
    jsr routine_c0df48
    rtl
