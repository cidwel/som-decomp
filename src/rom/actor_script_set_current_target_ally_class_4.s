; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
find_first_eligible_ally_class_4 = $0B7A

.segment "CODE"
.org $13D3
actor_script_set_current_target_ally_class_4:
    .a8
    lda #$FF
    sta a:$01AC,Y
    jsr find_first_eligible_ally_class_4
    .a8
    cmp #$FF
    beq actor_script_set_current_target_ally_class_4_c113e2
    sta a:$01AC,Y
actor_script_set_current_target_ally_class_4_c113e2:
    jmp advance_actor_script_1_bytes
