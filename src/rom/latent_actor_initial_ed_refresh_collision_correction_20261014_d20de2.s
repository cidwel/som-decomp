; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0DE2
actor_collision_byte_d20de2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $F0
actor_collision_byte_d20de3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $42
