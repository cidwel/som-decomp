; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

release_random_fallback_object_long = $D3FE39

.segment "CODE"
.org $4815
release_random_fallback_scheduler_object:
    jsl f:release_random_fallback_object_long
    rts
