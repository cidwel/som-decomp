; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0859
actor_collision_byte_d30859:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d3085a:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
