; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

advance_random_fallback_particles = $FE71
spawn_random_fallback_particle = $FEFB

.segment "CODE"
.org $FFBD
update_random_fallback_object:
    phd
    php
    rep #$20
    dec a:$0148,X
    bne update_random_fallback_object_d3ffcf
    .a16
    lda #$0001
    sta a:$0148,X
    jsr spawn_random_fallback_particle
update_random_fallback_object_d3ffcf:
    phx
    jsr advance_random_fallback_particles
    plx
    clc
    adc a:$0146,X
    beq update_random_fallback_object_d3ffdd
    .a16
    lda #$FFFF
update_random_fallback_object_d3ffdd:
    plp
    pld
    rts
