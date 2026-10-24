; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_ally_within_class_8 = $0C9A

ACTOR_SECOND_TARGET = $01AD

.segment "CODE"
.org $15C9
actor_script_set_second_target_ally_within_class_8:
    .a8
    lda #$FF
    sta a:ACTOR_SECOND_TARGET,Y
    jsr find_first_eligible_ally_within_class_8
    .a8
    cmp #$FF
    beq actor_script_set_second_target_ally_within_class_8_c115d8
    sta a:ACTOR_SECOND_TARGET,Y
actor_script_set_second_target_ally_within_class_8_c115d8:
    jmp advance_actor_script_1_bytes
