; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_ally_class_2 = $0B33

.segment "CODE"
.org $13C1
actor_script_set_current_target_ally_class_2:
    .a8
    lda #$FF
    sta a:$01AC,Y
    jsr find_first_eligible_ally_class_2
    .a8
    cmp #$FF
    beq actor_script_set_current_target_ally_class_2_c113d0
    sta a:$01AC,Y
actor_script_set_current_target_ally_class_2_c113d0:
    jmp advance_actor_script_1_bytes
