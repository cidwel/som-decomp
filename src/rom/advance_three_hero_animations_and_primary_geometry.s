; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-step.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_animation_and_resume_native_frame_stream = $F4CB
publish_primary_hero_frame_geometry = $F1C7

.segment "CODE"
.org $F4AB
advance_three_hero_animations_and_primary_geometry:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$10
    .i16
    ldx #$0000
    jsr advance_actor_animation_and_resume_native_frame_stream
    .i16
    ldx #$0200
    jsr advance_actor_animation_and_resume_native_frame_stream
    .i16
    ldx #$0400
    jsr advance_actor_animation_and_resume_native_frame_stream
    jsr publish_primary_hero_frame_geometry
    plb
    rts
