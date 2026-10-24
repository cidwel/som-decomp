; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4D60
actor_collision_byte_d34d60:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E1
actor_collision_byte_d34d61:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $47
