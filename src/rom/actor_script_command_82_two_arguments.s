; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_and_yield = $0111

.segment "CODE"
.org $1F98
actor_script_command_82_two_arguments:
    .a8
    lda #$82
    sta a:$0140,Y
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$0141,Y
    lda f:$D04F17,X
    sta a:$0142,Y
    .a8
    lda #$03
    jmp advance_actor_script_and_yield
