; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7388
test_descriptor_seven_horizontal_target_distance_below_64:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0002,Y
    sec
    sbc a:$002B,X
    bpl test_descriptor_seven_horizontal_target_distance_below_64_c2739e
    eor $C7
    inc
test_descriptor_seven_horizontal_target_distance_below_64_c2739e:
    .a16
    cmp #$0040
    bcc test_descriptor_seven_horizontal_target_distance_below_64_c273a5
    clc
    rts
test_descriptor_seven_horizontal_target_distance_below_64_c273a5:
    sec
    rts
