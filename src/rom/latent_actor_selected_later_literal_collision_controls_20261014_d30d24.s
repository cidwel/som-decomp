; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $0D24
actor_collision_byte_d30d24:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $00
actor_collision_byte_d30d25:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $55
