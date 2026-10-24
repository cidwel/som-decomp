.setcpu "65816"
.segment "CODE"
.org $CE96
.include "radial_particle_motion_macros.inc"
particle_14_animation_phase:
    radial_particle_animation_phase $00
