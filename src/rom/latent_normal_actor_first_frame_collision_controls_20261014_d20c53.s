; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0C53
actor_collision_byte_d20c53:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d20c54:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
