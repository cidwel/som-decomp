; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-step.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01d942 = $1D942

.segment "CODE"
.org $F8B3
trigger_actor_program_under_native_animation_guards:
    sep #$20
    lda $52
    ora $FF
    ora $F1
    bne trigger_actor_program_under_native_animation_guards_c0f8ed
    lda $E8
    .a8
    and #$04
    bne trigger_actor_program_under_native_animation_guards_c0f8ed
    lda a:$E000,X
    bmi trigger_actor_program_under_native_animation_guards_c0f8ed
    .i16
    cpx #$0600
    bcs trigger_actor_program_under_native_animation_guards_c0f8e0
    lda a:$E00F,X
    bne trigger_actor_program_under_native_animation_guards_c0f8ed
    lda a:$E191,X
    bmi trigger_actor_program_under_native_animation_guards_c0f8ed
    bit $4E
    bpl trigger_actor_program_under_native_animation_guards_c0f8e9
    stz a:$E067,X
    bra trigger_actor_program_under_native_animation_guards_c0f8ed
trigger_actor_program_under_native_animation_guards_c0f8e0:
    lda a:$E044,X
    bmi trigger_actor_program_under_native_animation_guards_c0f8ed
    cpx $3A
    beq trigger_actor_program_under_native_animation_guards_c0f8ed
trigger_actor_program_under_native_animation_guards_c0f8e9:
    jsl f:routine_01d942
trigger_actor_program_under_native_animation_guards_c0f8ed:
    rts
