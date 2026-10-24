; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-update.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_party_message_queue_update = $C0005D
jump_public_preemptive_native_dialogue = $C00003

.segment "CODE"
.org $C786
update_idle_party_message_queue_or_preempt_requested_dialogue:
    sep #$20
    rep #$10
    lda $48
    bne update_idle_party_message_queue_or_preempt_requested_dialogue_c2c797
    lda $D0
    bne update_idle_party_message_queue_or_preempt_requested_dialogue_c2c796
    jsl f:jump_public_party_message_queue_update
update_idle_party_message_queue_or_preempt_requested_dialogue_c2c796:
    rtl
update_idle_party_message_queue_or_preempt_requested_dialogue_c2c797:
    ldx $D4
    phb
    jsl f:jump_public_preemptive_native_dialogue
    plb
    rep #$20
    lda a:$010E
    bne update_idle_party_message_queue_or_preempt_requested_dialogue_c2c7a6
update_idle_party_message_queue_or_preempt_requested_dialogue_c2c7a6:
    sep #$20
    lda a:$1D04
    lsr
    bcc update_idle_party_message_queue_or_preempt_requested_dialogue_c2c7af
    rtl
update_idle_party_message_queue_or_preempt_requested_dialogue_c2c7af:
    stz $48
    rtl
