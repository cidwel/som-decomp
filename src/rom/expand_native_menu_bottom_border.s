; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_border_interior_columns = $2596

.segment "CODE"
.org $2576
expand_native_menu_bottom_border:
    rep #$20
    phx
    .a16
    lda #$A020
    sta a:$9000,X
    inx
    inx
    .a16
    lda #$A024
    jsr expand_native_menu_border_interior_columns
    .a16
    lda #$E020
    sta a:$9000,X
    pla
    clc
    .a16
    adc #$0040
    tax
    sep #$20
    rts
