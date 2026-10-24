.setcpu "65816"
.segment "CODE"
.org $CE69
.include "radial_particle_motion_macros.inc"
particle_09_motion:
    radial_particle_motion $70, $26, $04, $90
