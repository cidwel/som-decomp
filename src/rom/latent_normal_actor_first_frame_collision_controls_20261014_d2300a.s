; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $300A
actor_collision_byte_d2300a:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d2300b:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $54
