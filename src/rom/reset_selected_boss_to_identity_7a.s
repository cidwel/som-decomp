; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

change_actor_identity_public_jump = $C0003F

.segment "CODE"
.org $6292
reset_selected_boss_to_identity_7a:
    ldx $87
    .a16
    lda #$007A
    jsl f:change_actor_identity_public_jump
    rts
