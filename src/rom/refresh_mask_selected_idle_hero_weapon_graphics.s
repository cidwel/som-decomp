; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00e9f4 = $E9F4

.segment "CODE"
.org $DBAE
refresh_mask_selected_idle_hero_weapon_graphics:
    xba
    .a8
    lda #$00
    rep #$30
    tax
    sep #$20
    lda a:$E060,X
    bne refresh_mask_selected_idle_hero_weapon_graphics_c1dbc5
    stz a:$E069,X
    stz a:$E104,X
    jsl f:routine_00e9f4
refresh_mask_selected_idle_hero_weapon_graphics_c1dbc5:
    rts
