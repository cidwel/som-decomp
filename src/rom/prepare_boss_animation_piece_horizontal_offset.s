; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1EEB
prepare_boss_animation_piece_horizontal_offset:
    lda [$79]
    clc
    adc $93
    sta $6C
    lda $8D
    .a8
    bit #$40
    beq prepare_boss_animation_piece_horizontal_offset_c21f02
    lda $70
    clc
    adc $6C
    .a8
    eor #$FF
    inc
    sta $6C
prepare_boss_animation_piece_horizontal_offset_c21f02:
    lda $6C
    sta ($7C)
    rts
