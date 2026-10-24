; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

send_combat_sound_with_fixed_parameter_fifteen = $398D

.segment "CODE"
.org $3D5F
advance_status_damage_timer_and_apply_nonlethal_hp_loss:
    lda a:$E191,X
    .a8
    bit #$60
    beq advance_status_damage_timer_and_apply_nonlethal_hp_loss_c03d85
    dec a:$E1B6,X
    beq advance_status_damage_timer_and_apply_nonlethal_hp_loss_c03d86
    lda $80
    .a8
    ora #$40
    sta $80
    rep #$20
    lda a:$E182,X
    beq advance_status_damage_timer_and_apply_nonlethal_hp_loss_c03d86
    dec
    beq advance_status_damage_timer_and_apply_nonlethal_hp_loss_c03d86
    sta a:$E182,X
    sep #$20
    .a8
    lda #$39
    jsr send_combat_sound_with_fixed_parameter_fifteen
advance_status_damage_timer_and_apply_nonlethal_hp_loss_c03d85:
    rts
advance_status_damage_timer_and_apply_nonlethal_hp_loss_c03d86:
    sep #$20
    lda a:$E191,X
    .a8
    and #$9F
    sta a:$E191,X
    rts
