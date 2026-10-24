; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0D4C
actor_collision_byte_d30d4c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d30d4d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $47
