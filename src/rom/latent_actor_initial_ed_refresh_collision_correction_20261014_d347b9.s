; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $47B9
actor_collision_byte_d347b9:
    ; signed-XY-nibbles into actorCC collision box
    .byte $10
actor_collision_byte_d347ba:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $33
