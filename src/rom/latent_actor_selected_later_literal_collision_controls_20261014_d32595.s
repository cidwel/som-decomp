; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $2595
actor_collision_byte_d32595:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d32596:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $87
actor_collision_byte_d32597:
    ; signed-XY-nibbles into actorCC collision box
    .byte $00
actor_collision_byte_d32598:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $75
