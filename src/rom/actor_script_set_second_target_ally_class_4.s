; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_ally_class_4 = $0B7A

.segment "CODE"
.org $1581
actor_script_set_second_target_ally_class_4:
    .a8
    lda #$FF
    sta a:$01AD,Y
    jsr find_first_eligible_ally_class_4
    .a8
    cmp #$FF
    beq actor_script_set_second_target_ally_class_4_c11590
    sta a:$01AD,Y
actor_script_set_second_target_ally_class_4_c11590:
    jmp advance_actor_script_1_bytes
