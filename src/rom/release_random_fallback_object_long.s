; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

release_random_fallback_object = $FE3D

.segment "CODE"
.org $FE39
release_random_fallback_object_long:
    jsr release_random_fallback_object
    rtl
