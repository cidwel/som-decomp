; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-party-services.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_boss_random_tables_and_cast_queues_preserving_context = $001B

.segment "CODE"
.org $000F
public_boss_random_initialization_jump:
    jmp initialize_boss_random_tables_and_cast_queues_preserving_context
