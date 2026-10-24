; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $092C
actor_collision_byte_d3092c:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3092d:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
