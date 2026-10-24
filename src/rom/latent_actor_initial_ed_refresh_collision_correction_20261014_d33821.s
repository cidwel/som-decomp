; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3821
actor_collision_byte_d33821:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d33822:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $66
