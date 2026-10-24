; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-enemy-group-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_animation_and_resume_native_frame_stream = $F4CB
public_boss_pool_update_jump = $C20003
publish_actor_frame_tiles_points_and_collision_rectangle = $F1CF

.segment "CODE"
.org $FD07
advance_selected_actor_frame_or_public_boss_pool:
    bit $5C
    bpl advance_selected_actor_frame_or_public_boss_pool_c0fd17
    lda a:$E060,X
    bmi advance_selected_actor_frame_or_public_boss_pool_c0fd1c
    rep #$20
    jsl f:public_boss_pool_update_jump
    rts
advance_selected_actor_frame_or_public_boss_pool_c0fd17:
    jsr advance_actor_animation_and_resume_native_frame_stream
    ldx $14
advance_selected_actor_frame_or_public_boss_pool_c0fd1c:
    jmp publish_actor_frame_tiles_points_and_collision_rectangle
