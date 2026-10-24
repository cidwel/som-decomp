.setcpu "65816"
.segment "CODE"
.org $CE39
.include "radial_particle_motion_macros.inc"
particle_03_motion:
    radial_particle_motion $90, $18, $04, $30
