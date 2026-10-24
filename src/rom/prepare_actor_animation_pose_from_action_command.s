; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DA34
prepare_actor_animation_pose_from_action_command:
    lda a:$E141,X
    sta a:$E011,X
    .a8
    lda #$40
    sta a:$E01C,X
    .a8
    lda #$80
    sta a:$E064,X
    .a8
    lda #$FF
    sta a:$E030,X
    stz a:$E006,X
    stz a:$E007,X
    stz a:$E008,X
    rtl
    rtl
