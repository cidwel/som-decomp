; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_event_radial_particle_workspace = $CE11
upload_event_radial_particle_graphics = $CD70

.segment "CODE"
.org $CD67
initialize_event_radial_particle_graphics_and_descriptors:
    rep #$10
    jsr upload_event_radial_particle_graphics
    jsr initialize_event_radial_particle_workspace
    rts
