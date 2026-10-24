; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1912
actor_collision_byte_d31912:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d31913:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
