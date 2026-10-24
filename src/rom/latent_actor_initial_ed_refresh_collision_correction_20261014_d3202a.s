; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $202A
actor_collision_byte_d3202a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d3202b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
