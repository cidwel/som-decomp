; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_monster_within_class_2 = $0E96

.segment "CODE"
.org $1475
actor_script_set_current_target_monster_within_class_2:
    .a8
    lda #$FF
    sta a:$01AC,Y
    jsr find_first_eligible_monster_within_class_2
    .a8
    cmp #$FF
    beq actor_script_set_current_target_monster_within_class_2_c11484
    sta a:$01AC,Y
actor_script_set_current_target_monster_within_class_2_c11484:
    jmp advance_actor_script_1_bytes
