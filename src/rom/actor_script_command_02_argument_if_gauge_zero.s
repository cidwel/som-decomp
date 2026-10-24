; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_2_bytes = $012B
advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1D8E
actor_script_command_02_argument_if_gauge_zero:
    lda a:$01ED,Y
    beq actor_script_command_02_argument_if_gauge_zero_c11d96
    jmp advance_actor_script_2_bytes
actor_script_command_02_argument_if_gauge_zero_c11d96:
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$019B,Y
    .a8
    lda #$02
    sta a:$0140,Y
    .a8
    lda #$02
    jmp advance_actor_script_and_yield
