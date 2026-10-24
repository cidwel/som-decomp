; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1D52
actor_script_command_01:
    .a8
    lda #$01
    sta a:$0140,Y
    .a8
    lda #$01
    jmp advance_actor_script_and_yield
