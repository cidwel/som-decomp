; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_guarded_actor_cast_request_and_party_graphics = $88C7

.segment "CODE"
.org $DA00
prepare_actor_cast_pose_from_action_command:
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
    jsr prepare_guarded_actor_cast_request_and_party_graphics
    rtl
