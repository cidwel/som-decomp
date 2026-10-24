; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1F66
actor_script_command_c0_quantized_low_x:
    .a8
    lda #$C0
    sta a:$0140,Y
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$0141,Y
    lda f:$D04F17,X
    sta a:$0142,Y
    lda a:$0020,Y
    lsr
    clc
    .a8
    adc #$04
    lsr
    lsr
    lsr
    bne actor_script_command_c0_quantized_low_x_c11f8a
    .a8
    lda #$01
actor_script_command_c0_quantized_low_x_c11f8a:
    .a8
    cmp #$10
    bcc actor_script_command_c0_quantized_low_x_c11f90
    .a8
    lda #$0F
actor_script_command_c0_quantized_low_x_c11f90:
    sta a:$0143,Y
    .a8
    lda #$03
    jmp advance_actor_script_and_yield
