; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $327B
actor_collision_byte_d2327b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d2327c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $53
