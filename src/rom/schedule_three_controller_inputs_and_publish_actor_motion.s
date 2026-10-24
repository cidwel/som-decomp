; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-schedule.md.
.setcpu "65816"
.smart
.a8
.i16

produce_hero_signed_velocity_pose_and_energy_from_controller = $B710
schedule_controller_interaction_charge_and_deferred_attacks = $B799

.segment "CODE"
.org $B69C
schedule_three_controller_inputs_and_publish_actor_motion:
    sep #$30
    bit $F1
    bvs schedule_three_controller_inputs_and_publish_actor_motion_c0b6b6
    bmi schedule_three_controller_inputs_and_publish_actor_motion_c0b6c6
    lda $FF
    ora $52
    bne schedule_three_controller_inputs_and_publish_actor_motion_c0b6b6
    lda $E2
    .a8
    and #$01
    bne schedule_three_controller_inputs_and_publish_actor_motion_c0b6b6
    lda $E8
    .a8
    and #$04
    beq schedule_three_controller_inputs_and_publish_actor_motion_c0b6c7
schedule_three_controller_inputs_and_publish_actor_motion_c0b6b6:
    rep #$20
    stz $42
    stz $44
    stz $46
    sep #$20
    stz $CC
    stz $CD
    stz $CE
schedule_three_controller_inputs_and_publish_actor_motion_c0b6c6:
    rts
schedule_three_controller_inputs_and_publish_actor_motion_c0b6c7:
    jsr schedule_controller_interaction_charge_and_deferred_attacks
    sep #$30
    phb
    .a8
    lda #$7E
    pha
    plb
    lda $42
    sta $12
    lda $43
    sta $10
    lda $D9
    beq schedule_three_controller_inputs_and_publish_actor_motion_c0b6e4
    bmi schedule_three_controller_inputs_and_publish_actor_motion_c0b6e4
    sta $11
    jsr produce_hero_signed_velocity_pose_and_energy_from_controller
schedule_three_controller_inputs_and_publish_actor_motion_c0b6e4:
    sep #$30
    lda $44
    sta $12
    lda $45
    sta $10
    lda $DA
    beq schedule_three_controller_inputs_and_publish_actor_motion_c0b6f9
    bmi schedule_three_controller_inputs_and_publish_actor_motion_c0b6f9
    sta $11
    jsr produce_hero_signed_velocity_pose_and_energy_from_controller
schedule_three_controller_inputs_and_publish_actor_motion_c0b6f9:
    sep #$30
    lda $46
    sta $12
    lda $47
    sta $10
    lda $DB
    beq schedule_three_controller_inputs_and_publish_actor_motion_c0b70e
    bmi schedule_three_controller_inputs_and_publish_actor_motion_c0b70e
    sta $11
    jsr produce_hero_signed_velocity_pose_and_energy_from_controller
schedule_three_controller_inputs_and_publish_actor_motion_c0b70e:
    plb
    rts
