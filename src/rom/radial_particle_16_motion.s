.setcpu "65816"
.segment "CODE"
.org $CEA1
.include "radial_particle_motion_macros.inc"
particle_16_motion:
    radial_particle_motion $74, $40, $01, $08
