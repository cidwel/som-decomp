; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-chest-command.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_chest_reward_command = $C00066
routine_c1ebe1 = $EBE1

.segment "CODE"
.org $EBD4
open_chest_from_party_command:
    bne routine_c1ebe1
    rep #$30
    lda $D4
    ldx $3A
    jsl f:jump_public_chest_reward_command
    rts
