; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0C67
actor_collision_byte_d20c67:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d20c68:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
