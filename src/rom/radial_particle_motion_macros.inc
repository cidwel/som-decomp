.macro radial_particle_motion radial_scale_control, phase_accumulator, phase_increment, angle_quadrant_control
    .byte radial_scale_control, phase_accumulator, phase_increment, angle_quadrant_control
.endmacro

.macro radial_particle_animation_phase animation_accumulator
    .byte animation_accumulator
.endmacro
