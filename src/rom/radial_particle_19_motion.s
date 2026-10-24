.setcpu "65816"
.segment "CODE"
.org $CEB9
.include "radial_particle_motion_macros.inc"
particle_19_motion:
    radial_particle_motion $80, $40, $01, $C8
