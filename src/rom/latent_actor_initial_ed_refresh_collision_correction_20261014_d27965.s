; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $7965
actor_collision_byte_d27965:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d27966:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
