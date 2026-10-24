; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D992
disable_actor_from_action_command:
    .a8
    lda #$00
    sta a:$E000,X
    sta a:$E043,X
    rtl
