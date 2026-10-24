; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-animation.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_radial_particle_oam = $CD55
update_event_radial_particles = $CBEF
update_event_radial_window_and_wait_frame = $C9E0

.segment "CODE"
.org $C9D7
update_event_radial_window_and_particles:
    jsr update_event_radial_window_and_wait_frame
    jsr clear_event_radial_particle_oam
    brl update_event_radial_particles
