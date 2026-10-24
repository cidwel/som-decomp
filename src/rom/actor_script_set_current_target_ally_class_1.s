; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_ally_class_1 = $0AEC

.segment "CODE"
.org $13AF
actor_script_set_current_target_ally_class_1:
    .a8
    lda #$FF
    sta a:$01AC,Y
    jsr find_first_eligible_ally_class_1
    .a8
    cmp #$FF
    beq actor_script_set_current_target_ally_class_1_c113be
    sta a:$01AC,Y
actor_script_set_current_target_ally_class_1_c113be:
    jmp advance_actor_script_1_bytes
