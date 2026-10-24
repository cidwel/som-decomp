; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5F26
particle_frame_table = $5F26
particle_frame_014 = $5F3A
particle_frame_026 = $5F4C
particle_frame_038 = $5F5E
particle_frame_04a = $5F70
particle_frame_05c = $5F82
particle_frame_06e = $5F94
particle_frame_080 = $5FA6
particle_frame_092 = $5FB8
particle_frame_offsets:
    .word particle_frame_014 - particle_frame_table
    .word particle_frame_026 - particle_frame_table
    .word particle_frame_038 - particle_frame_table
    .word particle_frame_04a - particle_frame_table
    .word particle_frame_05c - particle_frame_table
    .word particle_frame_06e - particle_frame_table
    .word particle_frame_06e - particle_frame_table
    .word particle_frame_06e - particle_frame_table
    .word particle_frame_080 - particle_frame_table
    .word particle_frame_092 - particle_frame_table
