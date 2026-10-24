; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AAA
actor_collision_byte_d30aaa:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d30aab:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
