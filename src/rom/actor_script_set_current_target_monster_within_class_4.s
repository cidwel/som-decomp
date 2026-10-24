; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_monster_within_class_4 = $0EDF

.segment "CODE"
.org $1487
actor_script_set_current_target_monster_within_class_4:
    .a8
    lda #$FF
    sta a:$01AC,Y
    jsr find_first_eligible_monster_within_class_4
    .a8
    cmp #$FF
    beq actor_script_set_current_target_monster_within_class_4_c11496
    sta a:$01AC,Y
actor_script_set_current_target_monster_within_class_4_c11496:
    jmp advance_actor_script_1_bytes
