; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_four_by_four_tile_pattern = $26FC

.segment "CODE"
.org $26B3
consume_native_menu_four_by_four_pattern:
    ldx a:$0000,Y
    iny
    iny
    phb
    .a8
    lda #$7E
    pha
    plb
    phy
    .i16
    ldy #$0038
    .a8
    lda #$04
    sta a:$A178
consume_native_menu_four_by_four_pattern_c026c6:
    phx
    .a8
    lda #$04
    sta a:$A171
consume_native_menu_four_by_four_pattern_c026cc:
    phx
    tya
    phy
    jsr expand_native_menu_four_by_four_tile_pattern
    ply
    rep #$20
    pla
    clc
    .a16
    adc #$0008
    tax
    sep #$20
    tya
    .a8
    eor #$04
    tay
    dec a:$A171
    bne consume_native_menu_four_by_four_pattern_c026cc
    rep #$20
    pla
    clc
    .a16
    adc #$0100
    tax
    sep #$20
    tya
    .a8
    eor #$04
    tay
    dec a:$A178
    bne consume_native_menu_four_by_four_pattern_c026c6
    ply
    plb
    rts
