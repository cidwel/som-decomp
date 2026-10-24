; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1571
actor_collision_byte_d21571:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d21572:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
