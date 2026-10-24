; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $25FD
transfer_native_menu_palette_from_selected_bank:
    sta f:$004374
    rep #$20
    lda a:$A194
    sta f:$004372
    lda a:$A191
    sta f:$004375
    sep #$20
    .a8
    lda #$00
    sta f:$004370
    .a8
    lda #$22
    sta f:$004371
    .a8
    lda #$80
    sta f:$00420B
    rts
