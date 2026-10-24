; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_script_call_selected_effect_preserving_context = $1FB3
advance_actor_script_1_bytes = $0121
resolve_visible_current_actor_target = $05A5

.segment "CODE"
.org $1FC8
actor_script_apply_selected_effect_to_current_target:
    jsr resolve_visible_current_actor_target
    jsr actor_script_call_selected_effect_preserving_context
    jmp advance_actor_script_1_bytes
