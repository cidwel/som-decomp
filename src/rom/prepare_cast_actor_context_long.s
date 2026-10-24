; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_cast_actor_context = $3962



.segment "CODE"
.org $395E
prepare_cast_actor_context_long:
    jsr prepare_cast_actor_context
    rtl
