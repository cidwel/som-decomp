; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $4A56
actor_collision_byte_d34a56:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $01
actor_collision_byte_d34a57:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $64
