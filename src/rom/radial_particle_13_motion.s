.setcpu "65816"
.segment "CODE"
.org $CE89
.include "radial_particle_motion_macros.inc"
particle_13_motion:
    radial_particle_motion $80, $20, $03, $D0
