; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-parent-actions.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
prepare_native58_revive_cast_and_execute_success = $7DB5
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7CAB
native58_variant_zero_cast_or_charge:
    ldx $87
    lda a:$E990
    and a:$EB90
    bmi native58_variant_zero_cast_or_charge_c27cea
    lda a:$E990
    bpl native58_variant_zero_cast_or_charge_c27ccc
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne native58_variant_zero_cast_or_charge_c27ce1
    .a16
    lda #$0005
    sta $95
    jsr prepare_native58_revive_cast_and_execute_success
    bra native58_variant_zero_cast_or_charge_c27ce1
native58_variant_zero_cast_or_charge_c27ccc:
    lda a:$EB90
    bpl native58_variant_zero_cast_or_charge_c27ce1
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne native58_variant_zero_cast_or_charge_c27ce1
    .a16
    lda #$0006
    sta $95
    jsr prepare_native58_revive_cast_and_execute_success
native58_variant_zero_cast_or_charge_c27ce1:
    ldx $87
    .a16
    lda #$012F
    jsr select_boss_animation_and_reset_frame_cursor
    rts
native58_variant_zero_cast_or_charge_c27cea:
    lda a:$00B2,X
    bne native58_variant_zero_cast_or_charge_c27cf3
    inc a:$00B2,X
    rts
native58_variant_zero_cast_or_charge_c27cf3:
    inc a:$00B2,X
    lda a:$00B2,X
    .a16
    cmp #$0003
    bne native58_variant_zero_cast_or_charge_c27d0a
    .a16
    lda #$0120
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$8000
    sta a:$003E,X
native58_variant_zero_cast_or_charge_c27d0a:
    rts
