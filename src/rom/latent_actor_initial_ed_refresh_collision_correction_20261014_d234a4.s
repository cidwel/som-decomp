; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $34A4
actor_collision_byte_d234a4:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d234a5:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
