; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_hero_within_class_8 = $0A5A

ACTOR_CURRENT_TARGET = $01AC

.segment "CODE"
.org $139D
actor_script_set_current_target_hero_within_class_8:
    .a8
    lda #$FF
    sta a:ACTOR_CURRENT_TARGET,Y
    jsr find_first_eligible_hero_within_class_8
    .a8
    cmp #$FF
    beq actor_script_set_current_target_hero_within_class_8_c113ac
    sta a:ACTOR_CURRENT_TARGET,Y
actor_script_set_current_target_hero_within_class_8_c113ac:
    jmp advance_actor_script_1_bytes
