; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-public-death.md.
.setcpu "65816"
.smart
.a8
.i16

actor_death_public_context_and_reward_cleanup_wrapper = $4177

.segment "CODE"
.org $3857
actor_death_trampoline:
    jmp actor_death_public_context_and_reward_cleanup_wrapper
