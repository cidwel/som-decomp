; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1506
actor_collision_byte_d31506:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d31507:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d31508:
    ; signed-XY-nibbles into actorCC collision box
    .byte $30
actor_collision_byte_d31509:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $34
