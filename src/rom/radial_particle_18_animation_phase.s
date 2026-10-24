.setcpu "65816"
.segment "CODE"
.org $CEB6
.include "radial_particle_motion_macros.inc"
particle_18_animation_phase:
    radial_particle_animation_phase $03
