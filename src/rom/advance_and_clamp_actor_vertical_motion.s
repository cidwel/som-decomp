; Recovered Secret of Mana USA routine; behaviour documented in docs/map-actor-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D2C2
advance_and_clamp_actor_vertical_motion:
    bmi advance_and_clamp_actor_vertical_motion_c0d2d1
    clc
    adc a:$E045,X
    bpl advance_and_clamp_actor_vertical_motion_c0d2dc
    stz a:$E008,X
    .a8
    lda #$7F
    bra advance_and_clamp_actor_vertical_motion_c0d2dc
advance_and_clamp_actor_vertical_motion_c0d2d1:
    clc
    adc a:$E045,X
    bpl advance_and_clamp_actor_vertical_motion_c0d2dc
    stz a:$E008,X
    .a8
    lda #$00
advance_and_clamp_actor_vertical_motion_c0d2dc:
    sta a:$E045,X
    rts
