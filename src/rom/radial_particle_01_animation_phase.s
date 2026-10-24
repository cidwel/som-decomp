.setcpu "65816"
.segment "CODE"
.org $CE2E
.include "radial_particle_motion_macros.inc"
particle_01_animation_phase:
    radial_particle_animation_phase $01
