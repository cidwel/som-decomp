; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $314D
actor_collision_byte_d3314d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3314e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
