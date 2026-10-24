; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

compute_bounded_scene_target_angle_with_hardware_division = $900A
compute_wrapped_scene_target_deltas_and_direction_flags = $8E9E
initialize_scene_target_delta_continuation = $8E92

.segment "CODE"
.org $8E3B
initialize_scene_target_with_full_direction_branches:
    sep #$20
    .a8
    lda #$01
    sta $8C
    stz $8D
    lda $E3
    .a8
    bit #$06
    beq initialize_scene_target_with_full_direction_branches_c08e68
    .a8
    lda #$03
    sta $8F
    .a8
    lda #$FF
    sta $8E
    .a8
    lda #$E0
    sta $F8
    stz $F2
    .a8
    lda #$80
    sta $86
    rep #$20
    lda $FA
    sta $84
    lda $FC
    sta $88
    stz $8A
    rts
initialize_scene_target_with_full_direction_branches_c08e68:
    lsr
    bcc initialize_scene_target_delta_continuation
    jsr compute_wrapped_scene_target_deltas_and_direction_flags
    sep #$20
    stz $F2
    bit $8D
    bmi initialize_scene_target_with_full_direction_branches_c08e7a
    bvc initialize_scene_target_with_full_direction_branches_c08e82
    bvs initialize_scene_target_with_full_direction_branches_c08e7e
initialize_scene_target_with_full_direction_branches_c08e7a:
    bvc initialize_scene_target_with_full_direction_branches_c08e86
    bvs initialize_scene_target_with_full_direction_branches_c08e8a
initialize_scene_target_with_full_direction_branches_c08e7e:
    .a8
    lda #$03
    bra initialize_scene_target_with_full_direction_branches_c08e8c
initialize_scene_target_with_full_direction_branches_c08e82:
    .a8
    lda #$02
    bra initialize_scene_target_with_full_direction_branches_c08e8c
initialize_scene_target_with_full_direction_branches_c08e86:
    .a8
    lda #$01
    bra initialize_scene_target_with_full_direction_branches_c08e8c
initialize_scene_target_with_full_direction_branches_c08e8a:
    .a8
    lda #$00
initialize_scene_target_with_full_direction_branches_c08e8c:
    sta $F7
    jmp compute_bounded_scene_target_angle_with_hardware_division
