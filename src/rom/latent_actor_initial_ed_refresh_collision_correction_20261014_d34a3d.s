; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4A3D
actor_collision_byte_d34a3d:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34a3e:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
