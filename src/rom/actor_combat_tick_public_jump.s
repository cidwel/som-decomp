; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

actor_combat_tick_internal_jump = $3815

.segment "CODE"
.org $002D
actor_combat_tick_public_jump:
    jmp actor_combat_tick_internal_jump
