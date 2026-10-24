; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-frame-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_floating_number_bounce_hold_and_retirement = $8355
update_native_visual_effect_cadence_signed_motion_and_point_trail = $91E1
update_three_native_actor_effect_cells_and_restore_finished_actor = $8D80

.segment "CODE"
.org $833A
dispatch_actor_counter_or_spell_visual_effect_frame:
    sep #$20
    lda a:$E060,X
    .a8
    and #$E0
    .a8
    cmp #$40
    beq advance_floating_number_bounce_hold_and_retirement
    .a8
    cmp #$E0
    bne dispatch_actor_counter_or_spell_visual_effect_frame_c1834d
    jsr update_three_native_actor_effect_cells_and_restore_finished_actor
    rtl
dispatch_actor_counter_or_spell_visual_effect_frame_c1834d:
    .a8
    cmp #$C0
    bne dispatch_actor_counter_or_spell_visual_effect_frame_c18354
    jsr update_native_visual_effect_cadence_signed_motion_and_point_trail
dispatch_actor_counter_or_spell_visual_effect_frame_c18354:
    rtl
