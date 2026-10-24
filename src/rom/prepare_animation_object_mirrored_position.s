; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1978
prepare_animation_object_mirrored_position:
    sep #$20
    lda [$76],Y
    sta $99
    bpl prepare_animation_object_mirrored_position_c21984
    .a8
    lda #$FF
    sta $9A
prepare_animation_object_mirrored_position_c21984:
    iny
    lda [$76],Y
    sta $9B
    bpl prepare_animation_object_mirrored_position_c2198f
    .a8
    lda #$FF
    sta $9C
prepare_animation_object_mirrored_position_c2198f:
    iny
    phy
    rep #$20
    ldx $87
    lda a:$0098,X
    .a16
    bit #$0040
    beq prepare_animation_object_mirrored_position_c219a5
    lda $99
    .a16
    eor #$FFFF
    inc
    sta $99
prepare_animation_object_mirrored_position_c219a5:
    lda a:$0098,X
    .a16
    bit #$0080
    beq prepare_animation_object_mirrored_position_c219b5
    lda $9B
    .a16
    eor #$FFFF
    inc
    sta $9B
prepare_animation_object_mirrored_position_c219b5:
    lda a:$002B,X
    clc
    adc $99
    sta $9F
    lda a:$0032,X
    clc
    adc $9B
    sta $A1
    lda a:$0066,X
    sta $9D
    stx $A3
    ply
    rts
