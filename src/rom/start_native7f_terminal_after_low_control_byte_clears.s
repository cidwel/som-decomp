; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_native7f_terminal_palettes_rng_and_selected_actor_command = $96BD
request_audio_macro_eighty_with_operand_byte = $310A

.segment "CODE"
.org $96A5
start_native7f_terminal_after_low_control_byte_clears:
    ldx $87
    lda a:$0060,X
    .a16
    and #$00FF
    bne start_native7f_terminal_after_low_control_byte_clears_c296bb
    inc a:$0094,X
    jsr prepare_native7f_terminal_palettes_rng_and_selected_actor_command
    .a16
    lda #$00F0
    jsr request_audio_macro_eighty_with_operand_byte
start_native7f_terminal_after_low_control_byte_clears_c296bb:
    clc
    rts
