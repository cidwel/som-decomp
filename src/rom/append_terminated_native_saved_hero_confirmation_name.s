; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5394
append_terminated_native_saved_hero_confirmation_name:
    txy
    rep #$20
    jsr derive_selected_save_slot_primary_or_backup_offset
    stx a:$A171
    lda a:$A177
    .a16
    and #$00FF
    asl
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    clc
    adc a:$A171
    tax
    sep #$20
    .a8
    lda #$0C
append_terminated_native_saved_hero_confirmation_name_c753b6:
    xba
    lda f:$306003,X
    sta a:$9C00,Y
    beq append_terminated_native_saved_hero_confirmation_name_c753c6
    inx
    iny
    xba
    dec
    bne append_terminated_native_saved_hero_confirmation_name_c753b6
append_terminated_native_saved_hero_confirmation_name_c753c6:
    tyx
    rts
