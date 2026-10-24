; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

update_random_fallback_object = $FFBD

.segment "CODE"
.org $FFB9
update_random_fallback_object_long:
    jsr update_random_fallback_object
    rtl
