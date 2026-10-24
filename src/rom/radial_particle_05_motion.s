.setcpu "65816"
.segment "CODE"
.org $CE49
.include "radial_particle_motion_macros.inc"
particle_05_motion:
    radial_particle_motion $80, $1F, $04, $50
