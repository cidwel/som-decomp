; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0EE8
actor_collision_byte_d30ee8:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $11
actor_collision_byte_d30ee9:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d30eea:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d30eeb:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
