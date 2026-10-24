; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

begin_direct_actor_attack_from_action_command = $D99B
begin_guarded_party_attack_variant_from_action_command = $D9E3
clear_previous_directional_actor_pose = $D9A7
clone_action_actor_and_refresh_identity = $D9C4
disable_actor_from_action_command = $D992
dispatch_actor_audio_or_direction_command_with_literal_short_return = $DABE
dispatch_current_actor_pose_clone_or_cast_command = $DA22
replace_action_actor_identity_and_reset_motion = $DA84
routine_02b01e = $2B01E

.segment "CODE"
.org $D94D
dispatch_current_actor_action_command:
    sep #$20
    lda a:$E140,X
    bne dispatch_current_actor_action_command_c1d955
    rtl
dispatch_current_actor_action_command_c1d955:
    bmi dispatch_current_actor_action_command_c1d962
    .a8
    bit #$40
    beq dispatch_current_actor_action_command_c1d974
    .a8
    cmp #$45
    bcs dispatch_current_actor_action_command_c1d97e
    brl dispatch_current_actor_pose_clone_or_cast_command
dispatch_current_actor_action_command_c1d962:
    .a8
    bit #$40
    bne dispatch_current_actor_action_command_c1d96d
    .a8
    cmp #$81
    bne dispatch_current_actor_action_command_c1d97e
    brl replace_action_actor_identity_and_reset_motion
dispatch_current_actor_action_command_c1d96d:
    .a8
    cmp #$C2
    bcs dispatch_current_actor_action_command_c1d97e
    brl dispatch_actor_audio_or_direction_command_with_literal_short_return
dispatch_current_actor_action_command_c1d974:
    .a8
    cmp #$07
    bcc dispatch_current_actor_action_command_c1d97f
    bne dispatch_current_actor_action_command_c1d97e
    jml f:routine_02b01e
dispatch_current_actor_action_command_c1d97e:
    rtl
dispatch_current_actor_action_command_c1d97f:
    .a8
    cmp #$01
    beq clear_previous_directional_actor_pose
    .a8
    cmp #$02
    beq begin_direct_actor_attack_from_action_command
    .a8
    cmp #$04
    beq disable_actor_from_action_command
    .a8
    cmp #$05
    beq clone_action_actor_and_refresh_identity
    brl begin_guarded_party_attack_variant_from_action_command
