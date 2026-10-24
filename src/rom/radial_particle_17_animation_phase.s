.setcpu "65816"
.segment "CODE"
.org $CEAE
.include "radial_particle_motion_macros.inc"
particle_17_animation_phase:
    radial_particle_animation_phase $03
