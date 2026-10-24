; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1DB4
actor_script_command_07_clear_flag_if_set:
    lda a:$014C,Y
    .a8
    bit #$01
    beq actor_script_command_07_clear_flag_if_set_c11dca
    .a8
    and #$FE
    sta a:$014C,Y
    .a8
    lda #$07
    sta a:$0140,Y
    .a8
    lda #$01
    jmp advance_actor_script_and_yield
actor_script_command_07_clear_flag_if_set_c11dca:
    jmp advance_actor_script_1_bytes
