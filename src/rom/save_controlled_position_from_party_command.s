; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-snapshot-command.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_controlled_party_world_snapshot = $C00072
transfer_party_command_to_warm_reset = $EBEE

.segment "CODE"
.org $EBE1
save_controlled_position_from_party_command:
    .a8
    cmp #$10
    bne transfer_party_command_to_warm_reset
    rep #$30
    lda $D4
    jsl f:jump_public_controlled_party_world_snapshot
    rts
