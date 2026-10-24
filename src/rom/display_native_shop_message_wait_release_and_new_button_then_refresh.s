; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-dialogue.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_shop_vblank_input_and_active_ring_phase = $7E80
close_dialogue_public_jump = $C00095
routine_d0d5c1 = $D0D5C1
run_native_dialogue_public_jump = $C00092

.segment "CODE"
.org $7E95
display_native_shop_message_wait_release_and_new_button_then_refresh:
    rep #$30
    sep #$20
    .a8
    lda #$01
    bit a:$1D04
    beq display_native_shop_message_wait_release_and_new_button_then_refresh_c07ea6
    phx
    jsl f:close_dialogue_public_jump
    plx
display_native_shop_message_wait_release_and_new_button_then_refresh_c07ea6:
    .a8
    lda #$D9
    sta a:$1D03
    stx a:$1D01
    jsl f:run_native_dialogue_public_jump
    jsl f:routine_d0d5c1
display_native_shop_message_wait_release_and_new_button_then_refresh_c07eb6:
    rep #$30
    jsl f:routine_d0d5c1
    jsr advance_native_shop_vblank_input_and_active_ring_phase
    .a16
    bit #$CFC0
    bne display_native_shop_message_wait_release_and_new_button_then_refresh_c07eb6
display_native_shop_message_wait_release_and_new_button_then_refresh_c07ec4:
    jsr advance_native_shop_vblank_input_and_active_ring_phase
    .a16
    bit #$CFC0
    beq display_native_shop_message_wait_release_and_new_button_then_refresh_c07ec4
    sep #$20
    .a8
    lda #$80
    bit a:$1804
    bne display_native_shop_message_wait_release_and_new_button_then_refresh_c07ede
    .a8
    lda #$04
    tsb a:$1802
    jsl f:routine_d0d5c1
display_native_shop_message_wait_release_and_new_button_then_refresh_c07ede:
    rts
