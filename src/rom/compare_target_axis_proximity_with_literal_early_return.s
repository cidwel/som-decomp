; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-one.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3A63
compare_target_axis_proximity_with_literal_early_return:
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0002,X
    sta $95
    lda a:$0004,X
    sta $97
    ldx $87
    lda a:$002B,X
    sec
    sbc $95
    bpl compare_target_axis_proximity_with_literal_early_return_c23a85
    .a16
    eor #$FFFF
    inc
compare_target_axis_proximity_with_literal_early_return_c23a85:
    .a16
    cmp #$0010
    bcc compare_target_axis_proximity_with_literal_early_return_c23a99
    lda a:$0032,X
    sec
    sbc $97
    bpl compare_target_axis_proximity_with_literal_early_return_c23a96
    .a16
    eor #$FFFF
    inc
compare_target_axis_proximity_with_literal_early_return_c23a96:
    .a16
    cmp #$0008
compare_target_axis_proximity_with_literal_early_return_c23a99:
    rts
