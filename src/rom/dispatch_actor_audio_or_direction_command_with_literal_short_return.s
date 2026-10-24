; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

apply_actor_directional_command_and_reset_changed_pose = $DADD
audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $DABE
dispatch_actor_audio_or_direction_command_with_literal_short_return:
    .a8
    cmp #$C0
    bne apply_actor_directional_command_and_reset_changed_pose
    lda a:$E141,X
    sta a:$1E00
    lda a:$E142,X
    sta a:$1E01
    lda a:$E143,X
    sta a:$1E02
    phx
    jsl f:audio_command_sender_public_jump
    rep #$10
    plx
    rts
