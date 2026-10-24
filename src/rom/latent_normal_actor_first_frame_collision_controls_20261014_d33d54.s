; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3D54
actor_collision_byte_d33d54:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33d55:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
