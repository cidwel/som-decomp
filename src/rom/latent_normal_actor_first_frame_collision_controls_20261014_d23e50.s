; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3E50
actor_collision_byte_d23e50:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $10
actor_collision_byte_d23e51:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
