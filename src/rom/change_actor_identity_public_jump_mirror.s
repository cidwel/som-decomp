; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

change_actor_identity_and_attributes = $55EC

.segment "CODE"
.org $3827
change_actor_identity_public_jump_mirror:
    jmp change_actor_identity_and_attributes
