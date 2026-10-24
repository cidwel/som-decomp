; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-queue.md.
.setcpu "65816"
.smart
.a8
.i16

jump_internal_party_message_queue_update = $3845

.segment "CODE"
.org $005D
jump_public_party_message_queue_update:
    jmp jump_internal_party_message_queue_update
