; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

decrement_wrapped_ten_bit_coordinate_and_six_bit_countdown = $8113
request_sound_with_direct_page_volume = $8142
reset_native_stack_and_jump_from_ui_to_main_map_loop = $8255

.segment "CODE"
.org $8093
advance_ui_tile_buffers_and_native_transition_or_sound_requests:
    rep #$20
    lda $A2
    clc
    .a16
    adc #$0080
    .a16
    ora #$F000
    sta $A2
    .a16
    and #$03FF
    clc
    .a16
    adc #$2C00
    sta $A4
    sep #$20
    lda $E3
    .a8
    and #$06
    beq advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080ca
    rep #$20
    lda $92
    clc
    .a16
    adc #$0040
    .a16
    and #$03FF
    .a16
    ora #$EC00
    sta $92
    .a16
    and #$03FF
    clc
    .a16
    adc #$2800
    sta $94
advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080ca:
    sep #$30
    bit $FE
    bmi advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080e5
    bvs decrement_wrapped_ten_bit_coordinate_and_six_bit_countdown
    bit $E3
    bvc advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080e4
    lda $F5
    .a8
    bit #$01
    bne advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080e4
    lda $F4
    bne advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080e4
    .a8
    lda #$16
    bra request_sound_with_direct_page_volume
advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080e4:
    rts
advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080e5:
    rep #$20
    lda $F6
    clc
    .a16
    adc #$0010
    .a16
    and #$03FF
    sta $F6
    sep #$20
    lda $FE
    inc
    sta $FE
    .a8
    and #$3F
    beq advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080fe
    rts
advance_ui_tile_buffers_and_native_transition_or_sound_requests_c080fe:
    .a8
    lda #$00
    sta $FE
    .a8
    lda #$00
    sta $2D
    .a8
    lda #$44
    sta $F8
    rep #$10
    .a8
    lda #$00
    sta $E2
    jmp reset_native_stack_and_jump_from_ui_to_main_map_loop
