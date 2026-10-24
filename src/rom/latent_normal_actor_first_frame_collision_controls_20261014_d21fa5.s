; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1FA5
actor_collision_byte_d21fa5:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $11
actor_collision_byte_d21fa6:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
