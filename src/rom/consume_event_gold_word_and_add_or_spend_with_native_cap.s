; Recovered Secret of Mana USA routine; behaviour documented in docs/event-gold-hud-commands.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_party_gold_transaction = $C00057

.segment "CODE"
.org $EFE7
consume_event_gold_word_and_add_or_spend_with_native_cap:
    rep #$20
    .i8
    ldy #$01
    lda [$D1],Y
    inc $D1
    inc $D1
    inc $D1
    ldx $04
    jsl f:jump_public_party_gold_transaction
    rts
