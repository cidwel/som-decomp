; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-cells.md.
.setcpu "65816"
.smart
.a8
.i16

restore_actor_weapon_after_cast = $8DAB
routine_c18dbe = $8DBE
routine_c18dc5 = $8DC5
transfer_cast_presentation_to_target = $87C2

.segment "CODE"
.org $8D80
update_native_effect_cells_before_shared_weapon_restore:
    lda a:$E110,X
    ora a:$E120,X
    ora a:$E130,X
    beq update_native_effect_cells_before_shared_weapon_restore_c18d8d
    bra routine_c18dc5
update_native_effect_cells_before_shared_weapon_restore_c18d8d:
    rep #$20
    sep #$20
    stz a:$E104,X
    lda a:$E108,X
    bpl update_native_effect_cells_before_shared_weapon_restore_c18d9d
    txy
    jmp transfer_cast_presentation_to_target
update_native_effect_cells_before_shared_weapon_restore_c18d9d:
    sep #$20
    stz a:$E060,X
    .i16
    cpx #$0600
    bcc restore_actor_weapon_after_cast
    bit $ED
    bpl routine_c18dbe
