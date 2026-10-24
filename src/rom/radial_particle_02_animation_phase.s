.setcpu "65816"
.segment "CODE"
.org $CE36
.include "radial_particle_motion_macros.inc"
particle_02_animation_phase:
    radial_particle_animation_phase $03
