.setcpu "65816"
.segment "CODE"
.org $CEB1
.include "radial_particle_motion_macros.inc"
particle_18_motion:
    radial_particle_motion $70, $46, $01, $88
