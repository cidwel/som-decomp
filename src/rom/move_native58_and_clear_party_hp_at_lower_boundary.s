; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-setup.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native58_fractional_vertical_axis_and_rollback_on_collision = $7E08

.segment "CODE"
.org $7DE7
move_native58_and_clear_party_hp_at_lower_boundary:
    lda a:$003E,X
    beq move_native58_and_clear_party_hp_at_lower_boundary_c27e07
    jsr advance_native58_fractional_vertical_axis_and_rollback_on_collision
    ldx $87
    lda a:$0032,X
    .a16
    cmp #$0118
    bcc move_native58_and_clear_party_hp_at_lower_boundary_c27e07
    lda a:$0190,X
    bmi move_native58_and_clear_party_hp_at_lower_boundary_c27e07
    stz a:$E182
    stz a:$E382
    stz a:$E582
move_native58_and_clear_party_hp_at_lower_boundary_c27e07:
    rts
