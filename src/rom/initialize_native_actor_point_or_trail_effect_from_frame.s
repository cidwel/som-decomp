; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-producer.md.
.setcpu "65816"
.smart
.a8
.i16

decode_native_frame_point_targets_and_fractional_velocities = $A4A5

.segment "CODE"
.org $A480
initialize_native_actor_point_or_trail_effect_from_frame:
    ldx $14
    lda a:$E110,X
    .a8
    cmp #$05
    bcs initialize_native_actor_point_or_trail_effect_from_frame_c2a48f
    jsr decode_native_frame_point_targets_and_fractional_velocities
    ldx $14
    rtl
initialize_native_actor_point_or_trail_effect_from_frame_c2a48f:
    stz a:$E012,X
    .a8
    lda #$40
    sta a:$E114,X
    lda a:$E084,X
    sec
    .a8
    sbc #$04
    bpl initialize_native_actor_point_or_trail_effect_from_frame_c2a4a1
    .a8
    lda #$00
initialize_native_actor_point_or_trail_effect_from_frame_c2a4a1:
    sta a:$E116,X
    rtl
