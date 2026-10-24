; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1539
compose_dialogue_tile_mask_pair_rows:
    .a8
    lda #$08
    sta a:$A175
    ldx a:$A182
compose_dialogue_tile_mask_pair_rows_c01541:
    .a8
    lda #$FF
    sec
    sbc a:$9400,Y
    pha
    and f:$D2D480,X
    ora a:$9400,Y
    sta a:$9000,Y
    inx
    iny
    pla
    and f:$D2D480,X
    ora a:$9400,Y
    sta a:$9000,Y
    inx
    iny
    dec a:$A175
    bne compose_dialogue_tile_mask_pair_rows_c01541
    .a8
    lda #$08
    sta a:$A175
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    sep #$20
    ldx a:$A182
compose_dialogue_tile_mask_pair_rows_c01578:
    .a8
    lda #$FF
    sec
    sbc a:$9400,Y
    pha
    and f:$D2D480,X
    ora a:$9400,Y
    sta a:$9000,Y
    iny
    inx
    pla
    and f:$D2D480,X
    ora a:$9400,Y
    sta a:$9000,Y
    iny
    inx
    dec a:$A175
    bne compose_dialogue_tile_mask_pair_rows_c01578
    rts
