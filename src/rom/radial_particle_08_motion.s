.setcpu "65816"
.segment "CODE"
.org $CE61
.include "radial_particle_motion_macros.inc"
particle_08_motion:
    radial_particle_motion $70, $16, $03, $80
