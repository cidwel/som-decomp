.setcpu "65816"
.segment "CODE"
.org $CE51
.include "radial_particle_motion_macros.inc"
particle_06_motion:
    radial_particle_motion $90, $27, $03, $60
