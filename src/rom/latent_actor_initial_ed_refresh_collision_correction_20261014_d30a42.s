; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A42
actor_collision_byte_d30a42:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30a43:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
