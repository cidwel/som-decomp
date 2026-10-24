; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_script_call_native_cast_preserving_context = $1E16
actor_script_compare_mp_to_spell_argument_cost = $1E2C
advance_actor_script_and_yield = $0111
resolve_visible_second_actor_target = $05BA
write_actor_facing_fallback_command = $2534

.segment "CODE"
.org $1E47
actor_script_cast_single_second_target:
    jsr resolve_visible_second_actor_target
    bne actor_script_cast_single_second_target_c11e90
    jsr actor_script_compare_mp_to_spell_argument_cost
    bcc actor_script_cast_single_second_target_c11e90
    lda a:$0190,Y
    .a8
    and #$80
    bne actor_script_cast_single_second_target_c11e90
    lda a:$0060,Y
    .a8
    cmp #$E0
    beq actor_script_cast_single_second_target_c11e90
    .a8
    lda #$44
    sta a:$0140,Y
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$0141,Y
    lda f:$D04F17,X
    sta a:$0170,Y
    tyx
    stz a:$0177,X
    lda a:$01AD,X
    inc
    sta a:$0178,X
    stz a:$0179,X
    stz a:$017A,X
    .a8
    lda #$01
    sta a:$0176,X
    jsr actor_script_call_native_cast_preserving_context
    bra actor_script_cast_single_second_target_c11e93
actor_script_cast_single_second_target_c11e90:
    jsr write_actor_facing_fallback_command
actor_script_cast_single_second_target_c11e93:
    .a8
    lda #$03
    jmp advance_actor_script_and_yield
