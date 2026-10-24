; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16

construct_warm_particle_sprite_and_six_byte_workspace = $B342

.segment "CODE"
.org $B320
call_spawned_warm_particle_constructor:
    jsr construct_warm_particle_sprite_and_six_byte_workspace
