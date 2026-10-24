.setcpu "65816"
.segment "CODE"
.org $CE29
.include "radial_particle_motion_macros.inc"
particle_01_motion:
    radial_particle_motion $74, $10, $03, $10
