.setcpu "65816"
.segment "CODE"
.org $CE4E
.include "radial_particle_motion_macros.inc"
particle_05_animation_phase:
    radial_particle_animation_phase $02
