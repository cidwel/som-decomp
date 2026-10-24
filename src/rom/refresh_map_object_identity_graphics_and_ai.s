; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

change_actor_identity_public_jump = $C0003F
refresh_object_weapon_graphics_and_palette = $EA19
set_actor_program_long = $C10020

.segment "CODE"
.org $E038
refresh_map_object_identity_graphics_and_ai:
    sep #$20
    phx
    lda a:$E03D,X
    jsl f:change_actor_identity_public_jump
    rep #$10
    plx
    jsr refresh_object_weapon_graphics_and_palette
    rep #$10
    ldx $14
    sep #$20
    lda a:$E03D,X
    phx
    jsl f:set_actor_program_long
    plx
    rts
