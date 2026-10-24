; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $186C
place_animation_target_at_mirrored_signed_offsets:
    ldx $87
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    sep #$20
    stz $9A
    stz $9C
    lda [$76],Y
    sta $99
    bpl place_animation_target_at_mirrored_signed_offsets_c21888
    .a8
    lda #$FF
    sta $9A
place_animation_target_at_mirrored_signed_offsets_c21888:
    iny
    lda [$76],Y
    sta $9B
    bpl place_animation_target_at_mirrored_signed_offsets_c21893
    .a8
    lda #$FF
    sta $9C
place_animation_target_at_mirrored_signed_offsets_c21893:
    iny
    rep #$20
    lda a:$0098,X
    .a16
    bit #$0040
    beq place_animation_target_at_mirrored_signed_offsets_c218a6
    lda $99
    .a16
    eor #$FFFF
    inc
    sta $99
place_animation_target_at_mirrored_signed_offsets_c218a6:
    lda a:$0098,X
    .a16
    bit #$0080
    beq place_animation_target_at_mirrored_signed_offsets_c218b6
    lda $9B
    .a16
    eor #$FFFF
    inc
    sta $9B
place_animation_target_at_mirrored_signed_offsets_c218b6:
    lda a:$00A9,X
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda $95
    clc
    adc $99
    sta a:$0002,X
    lda $97
    clc
    adc $9B
    sta a:$0004,X
    ldx $87
    rts
