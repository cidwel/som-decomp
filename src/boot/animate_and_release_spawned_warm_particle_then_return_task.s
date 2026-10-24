; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16

publish_warm_particle_each_tick_until_animation_finishes = $B3A8
release_warm_particle_sprite_and_heap_workspace = $B416

.segment "CODE"
.org $B323
animate_and_release_spawned_warm_particle_then_return_task:
    stx $01
    jsr publish_warm_particle_each_tick_until_animation_finishes
    ldx $01
    jsr release_warm_particle_sprite_and_heap_workspace
    plb
    pla
    pla
    plp
    pld
    rtl
