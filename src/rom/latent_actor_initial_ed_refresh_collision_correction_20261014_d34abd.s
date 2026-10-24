; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4ABD
actor_collision_byte_d34abd:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $52
actor_collision_byte_d34abe:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
actor_collision_byte_d34abf:
    ; signed-XY-nibbles into actorCC collision box
    .byte $1F
actor_collision_byte_d34ac0:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $66
