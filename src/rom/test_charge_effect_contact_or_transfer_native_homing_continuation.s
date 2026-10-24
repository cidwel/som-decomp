; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_auxiliary_sprite_screen_position = $C4C9
select_opposing_charge_effect_contact_actor_and_mark_source = $C54E
steer_charge_effect_and_wrap_both_map_axes = $C681
test_charge_effect_homing_target_distance_threshold = $C64E

.segment "CODE"
.org $C526
test_charge_effect_contact_or_transfer_native_homing_continuation:
    jsr prepare_auxiliary_sprite_screen_position
    sep #$20
    lda a:$D000,Y
    .a8
    cmp #$03
    bcc select_opposing_charge_effect_contact_actor_and_mark_source
    lda a:$D008,Y
    .a8
    cmp #$FF
    bne test_charge_effect_contact_or_transfer_native_homing_continuation_c2c549
    pla
    pla
    jsr test_charge_effect_homing_target_distance_threshold
    bcs test_charge_effect_contact_or_transfer_native_homing_continuation_c2c546
    .a8
    lda #$00
    sta a:$D000,Y
    rts
test_charge_effect_contact_or_transfer_native_homing_continuation_c2c546:
    brl steer_charge_effect_and_wrap_both_map_axes
test_charge_effect_contact_or_transfer_native_homing_continuation_c2c549:
    jsr select_opposing_charge_effect_contact_actor_and_mark_source
    clc
    rts
