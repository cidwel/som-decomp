; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $403B
actor_collision_byte_d2403b:
    ; signed-XY-nibbles into actorCC collision box
    .byte $21
actor_collision_byte_d2403c:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $32
