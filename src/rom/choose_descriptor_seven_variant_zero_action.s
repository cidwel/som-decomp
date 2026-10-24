; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $712D
choose_descriptor_seven_variant_zero_action:
    ldx $87
    lda a:$0032,X
    sec
    sbc a:$0004,Y
    bmi choose_descriptor_seven_variant_zero_action_c27151
    .a16
    cmp #$0020
    bcs choose_descriptor_seven_variant_zero_action_c27151
    lda a:$002B,X
    cmp a:$0002,Y
    bcs choose_descriptor_seven_variant_zero_action_c2714b
    lda f:$DCE4F9
    clc
    rts
choose_descriptor_seven_variant_zero_action_c2714b:
    lda f:$DCE4FB
    clc
    rts
choose_descriptor_seven_variant_zero_action_c27151:
    lda a:$01B0,X
    .a16
    and #$00FF
    bne choose_descriptor_seven_variant_zero_action_c2715e
    .a16
    lda #$EB99
    clc
    rts
choose_descriptor_seven_variant_zero_action_c2715e:
    lda a:$002B,X
    cmp a:$0002,Y
    bcs choose_descriptor_seven_variant_zero_action_c2716c
    lda f:$DCE4FD
    clc
    rts
choose_descriptor_seven_variant_zero_action_c2716c:
    lda f:$DCE4FF
    clc
    rts
