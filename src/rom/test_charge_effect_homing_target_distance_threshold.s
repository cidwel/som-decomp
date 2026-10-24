; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C64E
test_charge_effect_homing_target_distance_threshold:
    rep #$20
    lda a:$E020,X
    sec
    sbc $04
    bpl test_charge_effect_homing_target_distance_threshold_c2c65c
    .a16
    eor #$FFFF
    inc
test_charge_effect_homing_target_distance_threshold_c2c65c:
    .a16
    cmp #$0008
    bcs test_charge_effect_homing_target_distance_threshold_c2c67e
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    clc
    adc a:$E022,X
    sec
    sbc $06
    bpl test_charge_effect_homing_target_distance_threshold_c2c67b
    .a16
    eor #$FFFF
    inc
test_charge_effect_homing_target_distance_threshold_c2c67b:
    .a16
    cmp #$0008
test_charge_effect_homing_target_distance_threshold_c2c67e:
    sep #$20
    rts
