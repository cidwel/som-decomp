; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D9A7
clear_previous_directional_actor_pose:
    lda a:$E067,X
    beq clear_previous_directional_actor_pose_c1d9c3
    stz a:$E006,X
    stz a:$E007,X
    stz a:$E008,X
    stz a:$E013,X
    stz a:$E011,X
    stz a:$E067,X
    .a8
    lda #$FF
    sta a:$E030,X
clear_previous_directional_actor_pose_c1d9c3:
    rtl
