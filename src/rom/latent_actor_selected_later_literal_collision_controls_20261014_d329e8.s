; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $29E8
actor_collision_byte_d329e8:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $20
actor_collision_byte_d329e9:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d329ea:
    ; signed-XY-nibbles into actorCC collision box
    .byte $D0
actor_collision_byte_d329eb:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $23
