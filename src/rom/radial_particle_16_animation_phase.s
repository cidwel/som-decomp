.setcpu "65816"
.segment "CODE"
.org $CEA6
.include "radial_particle_motion_macros.inc"
particle_16_animation_phase:
    radial_particle_animation_phase $01
