.setcpu "65816"
.segment "CODE"
.org $CE9E
.include "radial_particle_motion_macros.inc"
particle_15_animation_phase:
    radial_particle_animation_phase $00
