; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-queue.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_party_message_queue_and_dialogue = $57C9

.segment "CODE"
.org $3845
jump_internal_party_message_queue_update:
    jmp advance_native_party_message_queue_and_dialogue
