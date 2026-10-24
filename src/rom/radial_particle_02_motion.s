.setcpu "65816"
.segment "CODE"
.org $CE31
.include "radial_particle_motion_macros.inc"
particle_02_motion:
    radial_particle_motion $90, $28, $03, $20
