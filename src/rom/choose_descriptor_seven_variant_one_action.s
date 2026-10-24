; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16

compute_capped_boss_maximum_over_current_hp_ratio = $09B4
draw_boss_frame_random_number = $300B

.segment "CODE"
.org $7172
choose_descriptor_seven_variant_one_action:
    ldx $87
    lda a:$0032,X
    sec
    sbc a:$0004,Y
    bmi choose_descriptor_seven_variant_one_action_c271a6
    .a16
    cmp #$0020
    bcs choose_descriptor_seven_variant_one_action_c271a6
    lda a:$002B,X
    cmp a:$0002,Y
    bcs choose_descriptor_seven_variant_one_action_c27198
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE501,X
    clc
    rts
choose_descriptor_seven_variant_one_action_c27198:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE507,X
    clc
    rts
choose_descriptor_seven_variant_one_action_c271a6:
    lda a:$01B0,X
    .a16
    and #$00FF
    bne choose_descriptor_seven_variant_one_action_c271b3
    .a16
    lda #$EB99
    clc
    rts
choose_descriptor_seven_variant_one_action_c271b3:
    lda a:$002B,X
    cmp a:$0002,Y
    bcs choose_descriptor_seven_variant_one_action_c271d7
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcc choose_descriptor_seven_variant_one_action_c271d1
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE50D,X
    clc
    rts
choose_descriptor_seven_variant_one_action_c271d1:
    lda f:$DCE50D
    clc
    rts
choose_descriptor_seven_variant_one_action_c271d7:
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcc choose_descriptor_seven_variant_one_action_c271ed
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE511,X
    clc
    rts
choose_descriptor_seven_variant_one_action_c271ed:
    lda f:$DCE511
    clc
    rts
