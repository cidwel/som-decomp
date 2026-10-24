.setcpu "65816"
.segment "CODE"
.org $CE41
.include "radial_particle_motion_macros.inc"
particle_04_motion:
    radial_particle_motion $80, $0F, $02, $40
