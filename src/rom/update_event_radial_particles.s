; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-particles.md.
.setcpu "65816"
.smart
.a8
.i16

update_and_emit_event_radial_particle = $CC07

.segment "CODE"
.org $CBEF
update_event_radial_particles:
    rep #$10
    .i16
    ldy #$0000
    sty $08
update_event_radial_particles_c2cbf6:
    jsr update_and_emit_event_radial_particle
    rep #$20
    tya
    clc
    .a16
    adc #$0008
    tay
    .i16
    cpy #$00A0
    bcc update_event_radial_particles_c2cbf6
    rts
