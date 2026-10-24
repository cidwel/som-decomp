; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4020
actor_collision_byte_d34020:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d34021:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
actor_collision_byte_d34022:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d34023:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
