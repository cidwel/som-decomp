; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-public-death.md.
.setcpu "65816"
.smart
.a8
.i16

actor_death_trampoline = $3857

.segment "CODE"
.org $006F
public_actor_death_jump:
    jmp actor_death_trampoline
