.setcpu "65816"
.segment "CODE"
.org $CE8E
.include "radial_particle_motion_macros.inc"
particle_13_animation_phase:
    radial_particle_animation_phase $01
