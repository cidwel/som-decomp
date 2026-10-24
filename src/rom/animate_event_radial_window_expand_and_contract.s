; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-animation.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_radial_particle_oam = $CD55
update_event_radial_window_and_particles = $C9D7

.segment "CODE"
.org $C98B
animate_event_radial_window_expand_and_contract:
    rep #$30
    stz $18
animate_event_radial_window_expand_and_contract_c2c98f:
    jsr update_event_radial_window_and_particles
    sep #$20
    lda $18
    clc
    .a8
    adc #$01
    bcs animate_event_radial_window_expand_and_contract_c2c99f
    sta $18
    bra animate_event_radial_window_expand_and_contract_c2c98f
animate_event_radial_window_expand_and_contract_c2c99f:
    dec $19
animate_event_radial_window_expand_and_contract_c2c9a1:
    jsr update_event_radial_window_and_particles
    sep #$20
    lda $18
    sec
    .a8
    sbc #$01
    bcc animate_event_radial_window_expand_and_contract_c2c9b1
    sta $18
    bra animate_event_radial_window_expand_and_contract_c2c9a1
animate_event_radial_window_expand_and_contract_c2c9b1:
    jsr clear_event_radial_particle_oam
    sep #$20
    stz $2C
    .a8
    lda #$00
    sta f:$002125
    lda $21
    sta f:$00212C
    .a8
    lda #$02
    sta f:$002130
    lda $23
    sta f:$002131
    .a8
    lda #$E0
    sta f:$002132
    rts
