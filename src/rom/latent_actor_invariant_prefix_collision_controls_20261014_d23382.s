; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $3382
actor_collision_byte_d23382:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $11
actor_collision_byte_d23383:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $32
