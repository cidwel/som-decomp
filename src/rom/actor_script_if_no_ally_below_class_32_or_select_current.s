; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_ally_below_class_32 = $0CE3
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

ACTOR_CURRENT_TARGET = $01AC

.segment "CODE"
.org $0D20
actor_script_if_no_ally_below_class_32_or_select_current:
    jsr find_first_eligible_ally_below_class_32
    .a8
    cmp #$FF
    bne actor_script_if_no_ally_below_class_32_or_select_current_c10d2c
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_ally_below_class_32_or_select_current_c10d32
actor_script_if_no_ally_below_class_32_or_select_current_c10d2c:
    sta a:ACTOR_CURRENT_TARGET,Y
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_ally_below_class_32_or_select_current_c10d32:
    rts
