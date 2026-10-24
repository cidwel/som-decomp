.setcpu "65816"
.segment "CODE"
.org $CE91
.include "radial_particle_motion_macros.inc"
particle_14_motion:
    radial_particle_motion $90, $16, $02, $E0
