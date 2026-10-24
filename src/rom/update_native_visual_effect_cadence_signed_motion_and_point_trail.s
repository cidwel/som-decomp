; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-motion.md.
.setcpu "65816"
.smart
.a8
.i16

routine_02a407 = $2A407
routine_02aca8 = $2ACA8

.segment "CODE"
.org $91E1
update_native_visual_effect_cadence_signed_motion_and_point_trail:
    lda a:$E11E,X
    beq update_native_visual_effect_cadence_signed_motion_and_point_trail_c191ee
    dec a:$E11F,X
    bpl update_native_visual_effect_cadence_signed_motion_and_point_trail_c1922c
    sta a:$E11F,X
update_native_visual_effect_cadence_signed_motion_and_point_trail_c191ee:
    lda a:$E11C,X
    beq update_native_visual_effect_cadence_signed_motion_and_point_trail_c1920c
    .a8
    cmp #$80
    rep #$20
    bcc update_native_visual_effect_cadence_signed_motion_and_point_trail_c19202
    .a16
    and #$007F
    .a16
    eor #$FFFF
    inc
    bra update_native_visual_effect_cadence_signed_motion_and_point_trail_c19205
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19202:
    .a16
    and #$007F
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19205:
    clc
    adc a:$E118,X
    sta a:$E118,X
update_native_visual_effect_cadence_signed_motion_and_point_trail_c1920c:
    sep #$20
    lda a:$E11D,X
    beq update_native_visual_effect_cadence_signed_motion_and_point_trail_c1922c
    .a8
    cmp #$80
    rep #$20
    bcc update_native_visual_effect_cadence_signed_motion_and_point_trail_c19222
    .a16
    and #$007F
    .a16
    eor #$FFFF
    inc
    bra update_native_visual_effect_cadence_signed_motion_and_point_trail_c19225
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19222:
    .a16
    and #$007F
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19225:
    clc
    adc a:$E11A,X
    sta a:$E11A,X
update_native_visual_effect_cadence_signed_motion_and_point_trail_c1922c:
    sep #$20
    lda a:$E114,X
    bpl update_native_visual_effect_cadence_signed_motion_and_point_trail_c19238
    jsl f:routine_02a407
    rts
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19238:
    .a8
    bit #$40
    beq update_native_visual_effect_cadence_signed_motion_and_point_trail_c19246
    lda a:$E110,X
    .a8
    cmp #$05
    beq update_native_visual_effect_cadence_signed_motion_and_point_trail_c19247
    inc a:$E116,X
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19246:
    rts
update_native_visual_effect_cadence_signed_motion_and_point_trail_c19247:
    jsl f:routine_02aca8
    rts
