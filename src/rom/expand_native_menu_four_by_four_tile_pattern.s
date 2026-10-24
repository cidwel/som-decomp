; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $26FC
expand_native_menu_four_by_four_tile_pattern:
    xba
    .a8
    lda #$04
    sta a:$A175
expand_native_menu_four_by_four_tile_pattern_c02702:
    phx
    .a8
    lda #$04
    sta a:$A176
    .a8
    lda #$26
expand_native_menu_four_by_four_tile_pattern_c0270a:
    sta a:$9000,X
    inx
    xba
    sta a:$9000,X
    xba
    inx
    dec a:$A176
    bne expand_native_menu_four_by_four_tile_pattern_c0270a
    rep #$20
    tay
    pla
    clc
    .a16
    adc #$0040
    tax
    tya
    sep #$20
    dec a:$A175
    bne expand_native_menu_four_by_four_tile_pattern_c02702
    rts
