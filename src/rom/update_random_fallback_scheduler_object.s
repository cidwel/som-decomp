; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

update_random_fallback_object_long = $D3FFB9

.segment "CODE"
.org $481A
update_random_fallback_scheduler_object:
    jsl f:update_random_fallback_object_long
    rts
