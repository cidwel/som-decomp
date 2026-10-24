; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-input-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
dispatch_native_menu_idle_callback_when_selected_pad_is_empty = $2BA5
dispatch_pressed_native_menu_button_through_real_callback_table = $2B9A

.segment "CODE"
.org $2B06
dispatch_twelve_native_menu_button_bits_and_copy_previous_pads:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    phx
    stz a:$A209
    .a8
    lda #$80
    and $42,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$40
    and $42,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$20
    and $42,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$10
    and $42,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$80
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$40
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$20
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$10
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$08
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$04
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$02
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    .a8
    lda #$01
    and $43,X
    jsr dispatch_pressed_native_menu_button_through_real_callback_table
    inc a:$A209
    jsr dispatch_native_menu_idle_callback_when_selected_pad_is_empty
    plx
    .a8
    lda #$06
    .i16
    ldx #$0000
dispatch_twelve_native_menu_button_bits_and_copy_previous_pads_c02b8e:
    xba
    lda $42,X
    sta a:$A203,X
    inx
    xba
    dec
    bne dispatch_twelve_native_menu_button_bits_and_copy_previous_pads_c02b8e
    rts
