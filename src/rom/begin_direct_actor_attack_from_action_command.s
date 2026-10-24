; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00b287 = $B287

.segment "CODE"
.org $D99B
begin_direct_actor_attack_from_action_command:
    .a8
    lda #$80
    sta a:$E064,X
    stz a:$E085,X
    jml f:routine_00b287
