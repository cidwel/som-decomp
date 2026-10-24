; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1F88
reset_native_menu_publication_and_scroll_state:
    .a8
    lda #$80
    trb a:$A20A
    .a8
    lda #$00
    sta a:$A20C
    xba
    stz a:$A201
    rts
