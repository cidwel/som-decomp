; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_hero_class_4 = $0903

ACTOR_CURRENT_TARGET = $01AC

.segment "CODE"
.org $1343
actor_script_set_current_target_hero_class_4:
    .a8
    lda #$FF
    sta a:ACTOR_CURRENT_TARGET,Y
    jsr find_first_eligible_hero_class_4
    .a8
    cmp #$FF
    beq actor_script_set_current_target_hero_class_4_c11352
    sta a:ACTOR_CURRENT_TARGET,Y
actor_script_set_current_target_hero_class_4_c11352:
    jmp advance_actor_script_1_bytes
