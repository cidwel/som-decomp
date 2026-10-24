.setcpu "65816"
.segment "CODE"
.org $CE66
.include "radial_particle_motion_macros.inc"
particle_08_animation_phase:
    radial_particle_animation_phase $03
