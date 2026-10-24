.setcpu "65816"
.segment "CODE"
.org $CE79
.include "radial_particle_motion_macros.inc"
particle_11_motion:
    radial_particle_motion $90, $28, $04, $B0
