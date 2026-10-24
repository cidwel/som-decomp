.setcpu "65816"
.segment "CODE"
.org $CE59
.include "radial_particle_motion_macros.inc"
particle_07_motion:
    radial_particle_motion $90, $17, $02, $70
