; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1FC2
actor_collision_byte_d31fc2:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d31fc3:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
