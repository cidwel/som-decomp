; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6610
clear_native_ring_cursor_direct_page_words:
    rep #$20
    stz $CC
    stz $CD
    rts
