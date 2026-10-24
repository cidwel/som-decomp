; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_movement_charge_and_palette_effects = $CA6C

.segment "CODE"
.org $94EA
clear_actor_motion_and_graphic_state_before_refresh:
    jsr clear_actor_movement_charge_and_palette_effects
    lda a:$E060,X
    beq clear_actor_motion_and_graphic_state_before_refresh_c194f4
    sep #$20
clear_actor_motion_and_graphic_state_before_refresh_c194f4:
    stz a:$E01C,X
    stz a:$E011,X
    stz a:$E084,X
    stz a:$E060,X
    stz a:$E061,X
    stz a:$E064,X
    stz a:$E062,X
    stz a:$E00A,X
    rts
