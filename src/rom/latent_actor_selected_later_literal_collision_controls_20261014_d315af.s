; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $15AF
actor_collision_byte_d315af:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $E0
actor_collision_byte_d315b0:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $44
actor_collision_byte_d315b1:
    ; signed-XY-nibbles into actorCC collision box
    .byte $30
actor_collision_byte_d315b2:
    ; scaled-XY-extent-nibbles into actorCC collision box
    .byte $34
