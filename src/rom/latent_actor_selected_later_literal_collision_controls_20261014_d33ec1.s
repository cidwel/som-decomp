; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3EC1
actor_collision_byte_d33ec1:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d33ec2:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
