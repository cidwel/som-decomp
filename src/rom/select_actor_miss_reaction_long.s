; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

select_actor_random_miss_reaction = $4E6F

.segment "CODE"
.org $4E6B
select_actor_miss_reaction_long:
    jsr select_actor_random_miss_reaction
    rtl
