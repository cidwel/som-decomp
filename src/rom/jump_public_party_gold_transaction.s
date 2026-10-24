; Recovered Secret of Mana USA routine; behaviour documented in docs/event-gold-hud-commands.md.
.setcpu "65816"
.smart
.a8
.i16

jump_internal_party_gold_transaction = $383F

.segment "CODE"
.org $0057
jump_public_party_gold_transaction:
    jmp jump_internal_party_gold_transaction
