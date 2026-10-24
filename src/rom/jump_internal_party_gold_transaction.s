; Recovered Secret of Mana USA routine; behaviour documented in docs/event-gold-hud-commands.md.
.setcpu "65816"
.smart
.a8
.i16

add_or_spend_party_gold_with_saved_context = $39CF

.segment "CODE"
.org $383F
jump_internal_party_gold_transaction:
    jmp add_or_spend_party_gold_with_saved_context
