; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

event_command_native_context_wrapper = $E753

.segment "CODE"
.org $8000
event_command_public_jump:
    jmp event_command_native_context_wrapper
