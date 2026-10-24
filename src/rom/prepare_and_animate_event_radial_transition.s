; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-animation.md.
.setcpu "65816"
.smart
.a8
.i16

animate_event_radial_window_expand_and_contract = $C98B
build_event_radial_curve_lookup = $CB6F
initialize_event_radial_particle_graphics_and_descriptors = $CD67
prepare_event_radial_window_hdma = $CB1A

.segment "CODE"
.org $C976
prepare_and_animate_event_radial_transition:
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    jsr prepare_event_radial_window_hdma
    jsr initialize_event_radial_particle_graphics_and_descriptors
    jsr build_event_radial_curve_lookup
    jsr animate_event_radial_window_expand_and_contract
    plb
    rtl
