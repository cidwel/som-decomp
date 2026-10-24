; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8D89
compare_descriptor_eleven_horizontal_target_distance_with_48:
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$002B,X
    sec
    sbc a:$0002,Y
    bpl compare_descriptor_eleven_horizontal_target_distance_with_48_c28da1
    eor $C7
    inc
compare_descriptor_eleven_horizontal_target_distance_with_48_c28da1:
    .a16
    cmp #$0030
    rts
