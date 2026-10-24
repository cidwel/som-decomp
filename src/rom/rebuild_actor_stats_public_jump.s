; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_stats_mirror_jump = $381E



.segment "CODE"
.org $0036
rebuild_actor_stats_public_jump:
    jmp rebuild_actor_stats_mirror_jump
