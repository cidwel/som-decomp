; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-save-restart.md.
.setcpu "65816"
.smart
.a8
.i16

routine_008004 = $8004
routine_c1ebcb = $EBCB

.segment "CODE"
.org $EBC3
transfer_party_command_to_cold_reset:
    .a8
    cmp #$07
    bne routine_c1ebcb
    jml f:routine_008004
