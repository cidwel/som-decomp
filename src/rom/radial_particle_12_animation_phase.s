.setcpu "65816"
.segment "CODE"
.org $CE86
.include "radial_particle_motion_macros.inc"
particle_12_animation_phase:
    radial_particle_animation_phase $01
