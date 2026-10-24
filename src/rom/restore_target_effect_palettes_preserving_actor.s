; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-coordinator.md.
.setcpu "65816"
.smart
.a8
.i16

restore_actor_effect_palettes_unless_deferred = $CAAC

.segment "CODE"
.org $CA4F
restore_target_effect_palettes_preserving_actor:
    phy
    phx
    tyx
    jsr restore_actor_effect_palettes_unless_deferred
    plx
    ply
    rts
