; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CD5C
save_and_halve_one_menu_palette_color:
    lda a:$0600,X
    sta f:$7E8000,X
    lsr
    .a16
    and #$3DEF
    sta a:$0600,X
    inx
    inx
    rts
