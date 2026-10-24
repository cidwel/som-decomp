; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

derive_fine_direction_from_coordinate_pairs = $2E77

.segment "CODE"
.org $0965
derive_fine_direction_to_low_byte_target:
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0002,X
    sta $46
    lda a:$0004,X
    sta $4E
    ldx $87
    lda a:$002B,X
    sta $56
    lda a:$0032,X
    sta $5E
    jsr derive_fine_direction_from_coordinate_pairs
    rts
