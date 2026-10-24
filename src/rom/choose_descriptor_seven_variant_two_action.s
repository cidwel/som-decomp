; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16

compute_capped_boss_maximum_over_current_hp_ratio = $09B4
draw_boss_frame_random_number = $300B

.segment "CODE"
.org $71F3
choose_descriptor_seven_variant_two_action:
    ldx $87
    lda a:$0032,X
    sec
    sbc a:$0004,Y
    bmi choose_descriptor_seven_variant_two_action_c27227
    .a16
    cmp #$0020
    bcs choose_descriptor_seven_variant_two_action_c27227
    lda a:$002B,X
    cmp a:$0002,Y
    bcs choose_descriptor_seven_variant_two_action_c27219
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE515,X
    clc
    rts
choose_descriptor_seven_variant_two_action_c27219:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE519,X
    clc
    rts
choose_descriptor_seven_variant_two_action_c27227:
    lda a:$01B1,X
    .a16
    bit #$0040
    bne choose_descriptor_seven_variant_two_action_c27234
    .a16
    lda #$EB9B
    clc
    rts
choose_descriptor_seven_variant_two_action_c27234:
    lda a:$01B0,X
    .a16
    and #$00FF
    bne choose_descriptor_seven_variant_two_action_c27241
    .a16
    lda #$EB99
    clc
    rts
choose_descriptor_seven_variant_two_action_c27241:
    lda a:$002B,X
    cmp a:$0002,Y
    bcs choose_descriptor_seven_variant_two_action_c2725d
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcc choose_descriptor_seven_variant_two_action_c27257
    lda f:$DCE51F
    clc
    rts
choose_descriptor_seven_variant_two_action_c27257:
    lda f:$DCE51D
    clc
    rts
choose_descriptor_seven_variant_two_action_c2725d:
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcc choose_descriptor_seven_variant_two_action_c2726b
    lda f:$DCE523
    clc
    rts
choose_descriptor_seven_variant_two_action_c2726b:
    lda f:$DCE521
    clc
    rts
