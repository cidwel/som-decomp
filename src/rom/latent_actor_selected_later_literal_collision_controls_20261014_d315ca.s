; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $15CA
actor_collision_byte_d315ca:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d315cb:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d315cc:
    ; signed-XY-nibbles into actorCC collision box
    .byte $30
actor_collision_byte_d315cd:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $34
