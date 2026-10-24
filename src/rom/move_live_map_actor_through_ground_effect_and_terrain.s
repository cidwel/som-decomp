; Recovered Secret of Mana USA routine; behaviour documented in docs/map-actor-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_and_clamp_actor_vertical_motion = $D2C2
routine_c0d2e0 = $D2E0
routine_c0d74f = $D74F
routine_c0d890 = $D890

.segment "CODE"
.org $D229
move_live_map_actor_through_ground_effect_and_terrain:
    sep #$20
    stx $10
    lda a:$E000,X
    bne move_live_map_actor_through_ground_effect_and_terrain_c0d233
move_live_map_actor_through_ground_effect_and_terrain_c0d232:
    rts
move_live_map_actor_through_ground_effect_and_terrain_c0d233:
    bmi move_live_map_actor_through_ground_effect_and_terrain_c0d232
    lda a:$E036,X
    beq move_live_map_actor_through_ground_effect_and_terrain_c0d243
    dec a:$E037,X
    bmi move_live_map_actor_through_ground_effect_and_terrain_c0d240
    rts
move_live_map_actor_through_ground_effect_and_terrain_c0d240:
    sta a:$E037,X
move_live_map_actor_through_ground_effect_and_terrain_c0d243:
    lda a:$E060,X
    bmi move_live_map_actor_through_ground_effect_and_terrain_c0d250
    lda a:$E008,X
    beq move_live_map_actor_through_ground_effect_and_terrain_c0d250
    jsr advance_and_clamp_actor_vertical_motion
move_live_map_actor_through_ground_effect_and_terrain_c0d250:
    lda a:$E006,X
    sta $1E
    lda a:$E007,X
    sta $1F
    ldy $A8
    sty $16
    ldy $AA
    sty $18
    lda a:$E089,X
    .a8
    and #$03
    inc
    asl
    asl
    clc
    .a8
    adc #$06
    sta $1A
    lda a:$E00B,X
    sta $1B
    bpl move_live_map_actor_through_ground_effect_and_terrain_c0d27e
    ldy $AC
    sty $16
    ldy $AE
    sty $18
move_live_map_actor_through_ground_effect_and_terrain_c0d27e:
    rep #$20
    lda a:$E002,X
    sta $12
    lda a:$E004,X
    sta $14
    jsr routine_c0d2e0
    sep #$20
    lda $1F
    ora $1E
    bne move_live_map_actor_through_ground_effect_and_terrain_c0d296
    rts
move_live_map_actor_through_ground_effect_and_terrain_c0d296:
    ldx $10
    sep #$20
    bit $ED
    bpl move_live_map_actor_through_ground_effect_and_terrain_c0d2a4
    lda a:$E074,X
    asl
    bcc move_live_map_actor_through_ground_effect_and_terrain_c0d2be
move_live_map_actor_through_ground_effect_and_terrain_c0d2a4:
    jsr routine_c0d74f
    bcs move_live_map_actor_through_ground_effect_and_terrain_c0d2c1
    sep #$20
    rep #$10
    ldx $10
    lda $00
    .a8
    and #$04
    bne move_live_map_actor_through_ground_effect_and_terrain_c0d2be
    lda $01
    .a8
    and #$07
    beq move_live_map_actor_through_ground_effect_and_terrain_c0d2be
    sta a:$E08E,X
move_live_map_actor_through_ground_effect_and_terrain_c0d2be:
    jsr routine_c0d890
move_live_map_actor_through_ground_effect_and_terrain_c0d2c1:
    rts
