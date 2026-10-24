; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-coordinates.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DE82
expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five:
    phx
    pha
    lda a:$1880,X
    .a16
    and #$000F
    asl
    asl
    asl
    tax
    .i16
    ldy #$0000
expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five_d0de91:
    phx
    sep #$20
    lda f:$D9FF08,X
    tyx
    sta f:$7E8101,X
    sta f:$7E8110,X
    sta f:$7E8111,X
    .a8
    lda #$FF
    sta f:$7E8100,X
    rep #$20
    plx
    inx
    iny
    iny
    .i16
    cpy #$0010
    bne expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five_d0de91
    pla
    sep #$10
    sta a:$2116
    .i8
    ldx #$01
    stx a:$4350
    .i8
    ldx #$18
    stx a:$4351
    .a16
    lda #$8100
    sta a:$4352
    .i8
    ldx #$7E
    stx a:$4354
    .a16
    lda #$0020
    sta a:$4355
    .i8
    ldx #$20
    stx a:$420B
    rep #$30
    plx
    inx
    rts
