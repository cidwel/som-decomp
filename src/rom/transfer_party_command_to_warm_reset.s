; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-warm-restart.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c00075 = $C00075

.segment "CODE"
.org $EBEE
transfer_party_command_to_warm_reset:
    jml f:routine_c00075
