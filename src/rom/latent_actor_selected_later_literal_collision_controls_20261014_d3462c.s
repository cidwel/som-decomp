; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $462C
actor_collision_byte_d3462c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3462d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
