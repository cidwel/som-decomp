; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $68FF
clear_packed_menu_flag_then_open_native_ring:
    sep #$20
    .a8
    lda #$80
    trb a:$1803
