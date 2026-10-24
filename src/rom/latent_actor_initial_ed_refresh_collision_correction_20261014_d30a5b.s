; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A5B
actor_collision_byte_d30a5b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30a5c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
