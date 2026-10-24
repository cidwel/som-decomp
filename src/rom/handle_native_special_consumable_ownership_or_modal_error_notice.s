; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-consumable-action.md.
.setcpu "65816"
.smart
.a8
.i16

request_native_menu_audio_0e = $D0CF08
routine_c07271 = $7271
run_native_modal_menu_script_until_original_dialogue_closes = $D0D5B5

.segment "CODE"
.org $727F
handle_native_special_consumable_ownership_or_modal_error_notice:
    sep #$30
    ldx a:$19F1
    .a8
    lda #$80
    .i8
    cpx #$07
    beq handle_native_special_consumable_ownership_or_modal_error_notice_c07291
    lsr
    .i8
    cpx #$06
    beq handle_native_special_consumable_ownership_or_modal_error_notice_c07291
    bra handle_native_special_consumable_ownership_or_modal_error_notice_c07296
handle_native_special_consumable_ownership_or_modal_error_notice_c07291:
    bit a:$011F
    beq handle_native_special_consumable_ownership_or_modal_error_notice_c0729b
handle_native_special_consumable_ownership_or_modal_error_notice_c07296:
    jsl f:request_native_menu_audio_0e
    rts
handle_native_special_consumable_ownership_or_modal_error_notice_c0729b:
    lda a:$19F1
    clc
    .a8
    adc #$38
    asl
    tax
    rep #$30
    lda f:$CA0B82,X
    tax
    .a16
    lda #$00CA
    jsl f:run_native_modal_menu_script_until_original_dialogue_closes
    bra routine_c07271
