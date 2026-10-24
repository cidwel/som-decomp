; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1F25
prepare_boss_animation_piece_tile_attributes:
    lda $8E
    .a8
    bit #$80
    bne prepare_boss_animation_piece_tile_attributes_c21f35
    rep #$20
    .i8
    ldy #$02
    lda [$79],Y
    sta $6C
    bra prepare_boss_animation_piece_tile_attributes_c21f61
prepare_boss_animation_piece_tile_attributes_c21f35:
    rep #$20
    .i8
    ldy #$02
    lda [$79],Y
    sta $6E
    .a16
    and #$000F
    lsr
    sta $6A
    lda $6E
    .a16
    and #$01E0
    lsr
    lsr
    ora $6A
    tax
    lda a:$0ED5,X
    asl
    tax
    lda $6E
    .a16
    and #$FE00
    sta $6E
    lda f:$D97F35,X
    ora $6E
    sta $6C
prepare_boss_animation_piece_tile_attributes_c21f61:
    rep #$10
    ldx $87
    lda a:$00A3,X
    sep #$10
    xba
    asl
    clc
    adc $6C
    sta $6C
    lda $8D
    xba
    .a16
    and #$C000
    eor $6C
    .i8
    ldy #$02
    sta ($7C),Y
    sep #$20
    rts
