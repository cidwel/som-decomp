; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-recovery.md.
.setcpu "65816"
.smart
.a8
.i16

routine_0180ba = $180BA

.segment "CODE"
.org $EE83
event_initialize_actor_combat_state:
    sep #$20
    .a8
    lda #$FF
    jsl f:routine_0180ba
    rts
