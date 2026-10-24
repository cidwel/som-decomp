; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-dialogue.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_shop_vblank_input_and_active_ring_phase = $7E80
clear_native_menu_ring_blink_bit_in_twelve_rows = $7908
mark_selected_native_ring_row_and_return_owner_or_special_descriptor = $794A
routine_c07b81 = $7B81
routine_c07ed5 = $7ED5

.segment "CODE"
.org $7E30
confirm_native_shop_transaction_with_real_dialogue_and_controller:
    sep #$20
    .a8
    lda #$40
    tsb a:$1803
    jsr mark_selected_native_ring_row_and_return_owner_or_special_descriptor
    sep #$20
    .a8
    lda #$80
    tsb a:$1804
    rep #$30
    .i16
    ldx #$FEEC
    jsr routine_c07b81
    sep #$20
    .a8
    lda #$80
    trb a:$1804
confirm_native_shop_transaction_with_real_dialogue_and_controller_c07e50:
    sep #$20
    lda a:$1801
    .a8
    cmp #$80
    beq confirm_native_shop_transaction_with_real_dialogue_and_controller_c07e70
    .a8
    cmp #$40
    beq confirm_native_shop_transaction_with_real_dialogue_and_controller_c07e62
    jsr advance_native_shop_vblank_input_and_active_ring_phase
    bra confirm_native_shop_transaction_with_real_dialogue_and_controller_c07e50
confirm_native_shop_transaction_with_real_dialogue_and_controller_c07e62:
    sep #$20
    .a8
    lda #$02
    tsb a:$1803
    jsr routine_c07ed5
    sep #$20
    .a8
    lda #$01
confirm_native_shop_transaction_with_real_dialogue_and_controller_c07e70:
    php
    jsr clear_native_menu_ring_blink_bit_in_twelve_rows
    jsr advance_native_shop_vblank_input_and_active_ring_phase
    sep #$20
    .a8
    lda #$40
    trb a:$1803
    plp
    rts
