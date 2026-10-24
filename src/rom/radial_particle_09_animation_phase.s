.setcpu "65816"
.segment "CODE"
.org $CE6E
.include "radial_particle_motion_macros.inc"
particle_09_animation_phase:
    radial_particle_animation_phase $03
