; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1D5C
actor_script_command_02_copy_field_1c0_if_gauge_zero:
    lda a:$01ED,Y
    beq actor_script_command_02_copy_field_1c0_if_gauge_zero_c11d64
    jmp advance_actor_script_1_bytes
actor_script_command_02_copy_field_1c0_if_gauge_zero_c11d64:
    lda a:$01C0,Y
    sta a:$019B,Y
    .a8
    lda #$02
    sta a:$0140,Y
    .a8
    lda #$01
    jmp advance_actor_script_and_yield
