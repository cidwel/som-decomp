; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_and_clamp_actor_vertical_motion = $D2C2
resolve_hero_party_window_terrain_and_publish_motion = $D65D
routine_c0d2e0 = $D2E0

.segment "CODE"
.org $D5ED
move_live_hero_through_ground_terrain_and_camera:
    sep #$20
    rep #$10
    stx $10
    lda a:$E00F,X
    beq move_live_hero_through_ground_terrain_and_camera_c0d5fb
    bmi move_live_hero_through_ground_terrain_and_camera_c0d5fb
move_live_hero_through_ground_terrain_and_camera_c0d5fa:
    rts
move_live_hero_through_ground_terrain_and_camera_c0d5fb:
    lda a:$E000,X
    beq move_live_hero_through_ground_terrain_and_camera_c0d5fa
    bmi move_live_hero_through_ground_terrain_and_camera_c0d5fa
    lda a:$E036,X
    beq move_live_hero_through_ground_terrain_and_camera_c0d610
    dec a:$E037,X
    bmi move_live_hero_through_ground_terrain_and_camera_c0d60d
    rts
move_live_hero_through_ground_terrain_and_camera_c0d60d:
    sta a:$E037,X
move_live_hero_through_ground_terrain_and_camera_c0d610:
    lda a:$E060,X
    bmi move_live_hero_through_ground_terrain_and_camera_c0d61d
    lda a:$E008,X
    beq move_live_hero_through_ground_terrain_and_camera_c0d61d
    jsr advance_and_clamp_actor_vertical_motion
move_live_hero_through_ground_terrain_and_camera_c0d61d:
    lda a:$E006,X
    sta $1E
    lda a:$E007,X
    sta $1F
    ldy $A8
    sty $16
    ldy $AA
    sty $18
    .a8
    lda #$0C
    sta $1A
    lda a:$E00B,X
    sta $1B
    bpl move_live_hero_through_ground_terrain_and_camera_c0d642
    ldy $AC
    sty $16
    ldy $AE
    sty $18
move_live_hero_through_ground_terrain_and_camera_c0d642:
    rep #$20
    lda a:$E002,X
    sta $12
    lda a:$E004,X
    sta $14
    jsr routine_c0d2e0
    sep #$20
    lda $1F
    ora $1E
    beq move_live_hero_through_ground_terrain_and_camera_c0d65c
    jsr resolve_hero_party_window_terrain_and_publish_motion
move_live_hero_through_ground_terrain_and_camera_c0d65c:
    rts
