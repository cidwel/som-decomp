; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_movement_charge_and_palette_effects = $CA6C

.segment "CODE"
.org $8052
set_actor_motion_and_clear_previous_effects:
    php
    phy
    sep #$20
    sta a:$E011,X
    stz a:$E006,X
    stz a:$E007,X
    jsr clear_actor_movement_charge_and_palette_effects
    .a8
    lda #$40
    sta a:$E01C,X
    .a8
    lda #$80
    sta a:$E064,X
    ply
    plp
    rtl
