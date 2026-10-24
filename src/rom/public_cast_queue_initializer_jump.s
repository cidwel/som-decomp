; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

secondary_cast_queue_initializer_jump = $382D

.segment "CODE"
.org $0045
public_cast_queue_initializer_jump:
    jmp secondary_cast_queue_initializer_jump
