; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $19DA
actor_collision_byte_d319da:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d319db:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
