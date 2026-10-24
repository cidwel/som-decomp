; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-action-gates.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00e9f4 = $E9F4

.segment "CODE"
.org $AFE3
clear_actor_status_four_and_refresh_live_weapon_graphics:
    sep #$20
    lda a:$E000,X
    beq clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff3
    bmi clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff3
    lda a:$E191,X
    .a8
    bit #$C1
    beq clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff4
clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff3:
    rts
clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff4:
    .a8
    bit #$04
    beq clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff3
    .a8
    eor #$04
    sta a:$E191,X
    lda a:$E060,X
    bne clear_actor_status_four_and_refresh_live_weapon_graphics_c2aff3
    lda a:$E01C,X
    beq clear_actor_status_four_and_refresh_live_weapon_graphics_c2b011
    .a8
    cmp #$20
    beq clear_actor_status_four_and_refresh_live_weapon_graphics_c2b011
    stz a:$E01C,X
    stz a:$E011,X
clear_actor_status_four_and_refresh_live_weapon_graphics_c2b011:
    .a8
    lda #$FF
    sta f:$7EE030,X
    phx
    jsl f:routine_00e9f4
    plx
    rts
