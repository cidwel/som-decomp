; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

apply_actor_selected_effect_and_status = $C8E1ED

.segment "CODE"
.org $386E
actor_selected_effect_native_long_jump:
    jml f:apply_actor_selected_effect_and_status
