; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16

advance_warm_particle_sprite_and_random_hold_phase = $B3D3
routine_7eabe7 = $ABE7
routine_7eb7b9 = $B7B9

.segment "CODE"
.org $B3A8
publish_warm_particle_each_tick_until_animation_finishes:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    stx $01
publish_warm_particle_each_tick_until_animation_finishes_b3b3:
    ldy a:$0000,X
    tyx
    jsr routine_7eb7b9
    .i16
    ldx #$0001
    jsr routine_7eabe7
    ldx $01
    jsr advance_warm_particle_sprite_and_random_hold_phase
    ldx $01
    lda a:$0002,X
    .a8
    cmp #$0F
    bcc publish_warm_particle_each_tick_until_animation_finishes_b3b3
    pla
    pla
    plp
    pld
    rts
