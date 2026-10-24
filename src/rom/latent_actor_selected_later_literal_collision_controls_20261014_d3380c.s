; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $380C
actor_collision_byte_d3380c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3380d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
