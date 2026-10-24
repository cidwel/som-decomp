; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-step.md.
.setcpu "65816"
.smart
.a8
.i16

expand_actor_animation_frame_tiles_geometry_and_hitboxes = $F5AC
read_actor_animation_commands_and_native_nonlocal_returns = $F90B
refill_actor_slot_from_directional_circular_map_cache = $DFD4
routine_018089 = $18089
trigger_actor_program_under_native_animation_guards = $F8B3

.segment "CODE"
.org $F4CB
advance_actor_animation_and_resume_native_frame_stream:
    rep #$10
    stx $14
    sep #$20
    bit $F1
    bvs advance_actor_animation_and_resume_native_frame_stream_c0f4e2
    lda a:$E000,X
    bne advance_actor_animation_and_resume_native_frame_stream_c0f4e3
    .i16
    cpx #$0600
    bcc advance_actor_animation_and_resume_native_frame_stream_c0f4e2
    jmp refill_actor_slot_from_directional_circular_map_cache
advance_actor_animation_and_resume_native_frame_stream_c0f4e2:
    rts
advance_actor_animation_and_resume_native_frame_stream_c0f4e3:
    bmi advance_actor_animation_and_resume_native_frame_stream_c0f4fb
    lda a:$E043,X
    beq advance_actor_animation_and_resume_native_frame_stream_c0f4fb
    bmi advance_actor_animation_and_resume_native_frame_stream_c0f4fb
    pha
    phx
    jsr refill_actor_slot_from_directional_circular_map_cache
    plx
    sep #$20
    pla
    cmp a:$E043,X
    beq advance_actor_animation_and_resume_native_frame_stream_c0f4fb
    rts
advance_actor_animation_and_resume_native_frame_stream_c0f4fb:
    lda a:$E041,X
    beq advance_actor_animation_and_resume_native_frame_stream_c0f509
    dec
    sta a:$E041,X
    .a8
    lda #$FF
    sta a:$E030,X
advance_actor_animation_and_resume_native_frame_stream_c0f509:
    jsl f:routine_018089
    sep #$20
    lda a:$E060,X
    bmi advance_actor_animation_and_resume_native_frame_stream_c0f4e2
    lda a:$E02C,X
    ora a:$E01C,X
    ora a:$E060,X
    bne advance_actor_animation_and_resume_native_frame_stream_c0f52d
    lda a:$E00A,X
    ora a:$E064,X
    ora a:$E062,X
    bne advance_actor_animation_and_resume_native_frame_stream_c0f52d
    jsr trigger_actor_program_under_native_animation_guards
advance_actor_animation_and_resume_native_frame_stream_c0f52d:
    rep #$20
    .a16
    lda #$00D1
    sta $02
    lda a:$E010,X
    cmp a:$E030,X
    sta a:$E030,X
    sep #$20
    beq advance_actor_animation_and_resume_native_frame_stream_c0f590
    stz a:$E05D,X
    stz a:$E036,X
    stz a:$E05A,X
    .a8
    and #$0F
    sta $03
    stz $04
    lda a:$E01C,X
    beq advance_actor_animation_and_resume_native_frame_stream_c0f574
    stz a:$E013,X
    xba
    bpl advance_actor_animation_and_resume_native_frame_stream_c0f562
    rep #$20
    .a16
    and #$007F
    bra advance_actor_animation_and_resume_native_frame_stream_c0f57a
advance_actor_animation_and_resume_native_frame_stream_c0f562:
    rep #$20
    .a16
    and #$007F
    sta $00
    asl
    adc $00
    adc $03
    asl
    adc a:$E065,X
    bra advance_actor_animation_and_resume_native_frame_stream_c0f585
advance_actor_animation_and_resume_native_frame_stream_c0f574:
    rep #$20
    xba
    .a16
    and #$00FF
advance_actor_animation_and_resume_native_frame_stream_c0f57a:
    sta $00
    asl
    adc $00
    adc $03
    asl
    adc a:$E075,X
advance_actor_animation_and_resume_native_frame_stream_c0f585:
    sta $00
    lda [$00]
    sta a:$E018,X
    sta $00
    bra advance_actor_animation_and_resume_native_frame_stream_c0f5a1
advance_actor_animation_and_resume_native_frame_stream_c0f590:
    lda a:$E012,X
    beq advance_actor_animation_and_resume_native_frame_stream_c0f59a
    dec
    sta a:$E012,X
    rts
advance_actor_animation_and_resume_native_frame_stream_c0f59a:
    rep #$20
    lda a:$E016,X
    sta $00
advance_actor_animation_and_resume_native_frame_stream_c0f5a1:
    sep #$20
    lda [$00]
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes
    jsr read_actor_animation_commands_and_native_nonlocal_returns
    bcs advance_actor_animation_and_resume_native_frame_stream_c0f5a1
