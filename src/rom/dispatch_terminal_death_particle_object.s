; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3ADB
dispatch_terminal_death_particle_object:
    lda a:$0094,X
    asl
    tax
    jmp ($3AE3,X)
