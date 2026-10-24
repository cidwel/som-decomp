.setcpu "65816"
.segment "CODE"
.org $CEA9
.include "radial_particle_motion_macros.inc"
particle_17_motion:
    radial_particle_motion $90, $48, $01, $48
