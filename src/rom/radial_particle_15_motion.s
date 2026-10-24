.setcpu "65816"
.segment "CODE"
.org $CE99
.include "radial_particle_motion_macros.inc"
particle_15_motion:
    radial_particle_motion $90, $26, $02, $F0
