; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A8B
actor_collision_byte_d30a8b:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d30a8c:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $65
actor_collision_byte_d30a8d:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d30a8e:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
