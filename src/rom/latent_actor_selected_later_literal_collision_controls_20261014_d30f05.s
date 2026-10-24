; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0F05
actor_collision_byte_d30f05:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30f06:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d30f07:
    ; signed-XY-nibbles into actorCC collision box
    .byte $11
actor_collision_byte_d30f08:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $22
