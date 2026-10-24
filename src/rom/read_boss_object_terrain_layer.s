; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_boss_terrain_row_stride = $2AA6

.segment "CODE"
.org $1683
read_boss_object_terrain_layer:
    lda $3E
    lsr
    lsr
    lsr
    lsr
    sta $46
    .a16
    lda #$0080
    sta $4E
    sep #$20
    jsr multiply_boss_terrain_row_stride
    rep #$20
    lda $3C
    lsr
    lsr
    lsr
    lsr
    clc
    adc $56
    tay
    lda [$79],Y
    .a16
    and #$00FF
    asl
    asl
    tay
    lda [$7C],Y
    .a16
    and #$0003
    sep #$20
    sta a:$000B,X
    rep #$20
    rts
