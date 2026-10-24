; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3E97
actor_collision_byte_d23e97:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d23e98:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
