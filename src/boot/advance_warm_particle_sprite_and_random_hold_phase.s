; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B3D3
advance_warm_particle_sprite_and_random_hold_phase:
    phd
    php
    rep #$30
    sep #$20
    lda a:$0002,X
    .a8
    cmp #$07
    bcc advance_warm_particle_sprite_and_random_hold_phase_b3ee
    beq advance_warm_particle_sprite_and_random_hold_phase_b400
    inc a:$0002,X
    txy
    ldx a:$0000,Y
    dec a:$0006,X
    bra advance_warm_particle_sprite_and_random_hold_phase_b413
advance_warm_particle_sprite_and_random_hold_phase_b3ee:
    inc a:$0002,X
    txy
    ldx a:$0000,Y
    inc a:$0002,X
    dec a:$0004,X
    inc a:$0006,X
    bra advance_warm_particle_sprite_and_random_hold_phase_b413
advance_warm_particle_sprite_and_random_hold_phase_b400:
    txy
    ldx a:$0000,Y
    inc a:$0002,X
    dec a:$0004,X
    tyx
    dec a:$0004,X
    bne advance_warm_particle_sprite_and_random_hold_phase_b413
    inc a:$0002,X
advance_warm_particle_sprite_and_random_hold_phase_b413:
    plp
    pld
    rts
