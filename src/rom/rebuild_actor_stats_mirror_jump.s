; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_attributes_native = $4530



.segment "CODE"
.org $381E
rebuild_actor_stats_mirror_jump:
    jmp rebuild_actor_attributes_native
