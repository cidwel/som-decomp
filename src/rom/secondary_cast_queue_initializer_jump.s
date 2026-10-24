; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

clear_cast_queues_and_seed_fifteen_byte_random_pool = $38CE

.segment "CODE"
.org $382D
secondary_cast_queue_initializer_jump:
    jmp clear_cast_queues_and_seed_fifteen_byte_random_pool
