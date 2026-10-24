.setcpu "65816"
.segment "CODE"
.org $CE46
.include "radial_particle_motion_macros.inc"
particle_04_animation_phase:
    radial_particle_animation_phase $02
