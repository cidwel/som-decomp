; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16

compose_dialogue_tile_mask_pair_rows = $1539

.segment "CODE"
.org $1521
compose_second_dialogue_tile_bitplane_rows:
    .i16
    ldy #$0010
    .a8
    lda #$0E
compose_second_dialogue_tile_bitplane_rows_c01526:
    pha
    jsr compose_dialogue_tile_mask_pair_rows
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    sep #$20
    pla
    dec
    bne compose_second_dialogue_tile_bitplane_rows_c01526
    rts
