; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0995
actor_collision_byte_d30995:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30996:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
