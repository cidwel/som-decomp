; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1F07
prepare_boss_animation_piece_vertical_offset:
    .i8
    ldy #$01
    lda [$79],Y
    clc
    adc $94
    sta $6C
    lda $8D
    .a8
    bit #$80
    beq prepare_boss_animation_piece_vertical_offset_c21f20
    lda $70
    clc
    adc $6C
    .a8
    eor #$FF
    inc
    sta $6C
prepare_boss_animation_piece_vertical_offset_c21f20:
    lda $6C
    sta ($7C),Y
    rts
