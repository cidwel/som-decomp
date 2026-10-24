; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A70
actor_collision_byte_d30a70:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d30a71:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
actor_collision_byte_d30a72:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d30a73:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
