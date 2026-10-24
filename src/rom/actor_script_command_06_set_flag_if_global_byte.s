; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1DCD
actor_script_command_06_set_flag_if_global_byte:
    rep #$20
    tya
    sec
    .a16
    sbc #$E000
    lsr
    xba
    tax
    sep #$20
    lda f:$7ECC7D,X
    beq actor_script_command_06_set_flag_if_global_byte_c11df5
    lda a:$014C,Y
    .a8
    bit #$01
    bne actor_script_command_06_set_flag_if_global_byte_c11df5
    .a8
    ora #$01
    sta a:$014C,Y
    .a8
    lda #$06
    sta a:$0140,Y
    .a8
    lda #$01
    jmp advance_actor_script_and_yield
actor_script_command_06_set_flag_if_global_byte_c11df5:
    jmp advance_actor_script_1_bytes
