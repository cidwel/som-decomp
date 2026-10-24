; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-step.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0f52d = $F52D
trigger_actor_program_under_native_animation_guards = $F8B3

.segment "CODE"
.org $F8EE
restart_actor_frame_after_unwinding_reader_return:
    sep #$20
    .a8
    lda #$FF
    sta a:$E030,X
    lda a:$E02C,X
    ora a:$E060,X
    bne restart_actor_frame_after_unwinding_reader_return_c0f905
    lda a:$E064,X
    bpl restart_actor_frame_after_unwinding_reader_return_c0f905
    jsr trigger_actor_program_under_native_animation_guards
restart_actor_frame_after_unwinding_reader_return_c0f905:
    rep #$20
    pla
    jmp routine_c0f52d
