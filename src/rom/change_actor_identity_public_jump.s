; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

change_actor_identity_public_jump_mirror = $3827

.segment "CODE"
.org $003F
change_actor_identity_public_jump:
    jmp change_actor_identity_public_jump_mirror
