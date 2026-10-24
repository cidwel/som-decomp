; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6
routine_7eb786 = $B786

.segment "CODE"
.org $B416
release_warm_particle_sprite_and_heap_workspace:
    phd
    php
    rep #$30
    sep #$20
    phx
    ldy a:$0000,X
    tyx
    jsr routine_7eb786
    plx
    jsr routine_7eb0d6
    plp
    pld
    rts
