.setcpu "65816"
.segment "CODE"
.org $CE71
.include "radial_particle_motion_macros.inc"
particle_10_motion:
    radial_particle_motion $90, $18, $02, $A0
