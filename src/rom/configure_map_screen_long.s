; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

configure_map_screen = $AA60

.segment "CODE"
.org $AA5C
configure_map_screen_long:
    jsr configure_map_screen
    rtl
