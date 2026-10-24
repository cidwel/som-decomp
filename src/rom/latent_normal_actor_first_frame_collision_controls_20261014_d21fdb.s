; Functional actor collision positions/extents; tile and sprite records excluded.
.setcpu "65816"
.segment "RODATA"
.org $1FDB
actor_collision_byte_d21fdb:
    ; signed-XY-nibbles into actorC8 collision box
    .byte $11
actor_collision_byte_d21fdc:
    ; scaled-XY-extent-nibbles into actorC8 collision box
    .byte $33
