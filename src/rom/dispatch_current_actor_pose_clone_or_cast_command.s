; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

clone_action_actor_with_selected_identity = $DA54
prepare_actor_animation_pose_from_action_command = $DA34
prepare_actor_cast_pose_from_action_command = $DA00
routine_c1da53 = $DA53

.segment "CODE"
.org $DA22
dispatch_current_actor_pose_clone_or_cast_command:
    .a8
    cmp #$40
    beq prepare_actor_animation_pose_from_action_command
    .a8
    cmp #$41
    beq routine_c1da53
    .a8
    cmp #$42
    beq routine_c1da53
    .a8
    cmp #$43
    beq clone_action_actor_with_selected_identity
    bra prepare_actor_cast_pose_from_action_command
