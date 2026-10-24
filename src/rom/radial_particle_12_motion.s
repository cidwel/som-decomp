.setcpu "65816"
.segment "CODE"
.org $CE81
.include "radial_particle_motion_macros.inc"
particle_12_motion:
    radial_particle_motion $80, $00, $02, $C0
