; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_hero_class_8 = $094A

.segment "CODE"
.org $1503
actor_script_set_second_target_hero_class_8:
    .a8
    lda #$FF
    sta a:$01AD,Y
    jsr find_first_eligible_hero_class_8
    .a8
    cmp #$FF
    beq actor_script_set_second_target_hero_class_8_c11512
    sta a:$01AD,Y
actor_script_set_second_target_hero_class_8_c11512:
    jmp advance_actor_script_1_bytes
