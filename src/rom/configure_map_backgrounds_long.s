; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

configure_map_backgrounds = $FD52

.segment "CODE"
.org $FD4E
configure_map_backgrounds_long:
    jsr configure_map_backgrounds
    rtl
