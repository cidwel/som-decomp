.setcpu "65816"
.segment "CODE"
.org $CE21
.include "radial_particle_motion_macros.inc"
particle_00_motion:
    radial_particle_motion $74, $00, $02, $00
