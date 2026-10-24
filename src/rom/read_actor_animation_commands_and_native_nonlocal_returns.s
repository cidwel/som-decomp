; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-step.md.
.setcpu "65816"
.smart
.a8
.i16

restart_actor_frame_after_unwinding_reader_return = $F8EE
routine_018707 = $18707
routine_01d48d = $1D48D
routine_01d52a = $1D52A
routine_01d5c0 = $1D5C0
routine_01d6dc = $1D6DC
routine_02bf1d = $2BF1D

.segment "CODE"
.org $F90B
read_actor_animation_commands_and_native_nonlocal_returns:
    .a8
    cmp #$FF
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f976
    .a8
    lda #$00
    sta a:$E012,X
    lda a:$E05D,X
    beq read_actor_animation_commands_and_native_nonlocal_returns_c0f925
    stz a:$E05D,X
    rep #$20
    lda a:$E05E,X
    sta $00
    sec
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f925:
    lda a:$E01C,X
    beq restart_actor_frame_after_unwinding_reader_return
    bpl read_actor_animation_commands_and_native_nonlocal_returns_c0f949
    stz a:$E01A,X
    stz a:$E01B,X
read_actor_animation_commands_and_native_nonlocal_returns_c0f932:
    lda a:$E061,X
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f955
    stz a:$E19B,X
    .a8
    lda #$64
    sec
    sbc a:$E189,X
    lsr
    clc
    .a8
    adc #$32
    sta a:$E1ED,X
    bra read_actor_animation_commands_and_native_nonlocal_returns_c0f955
read_actor_animation_commands_and_native_nonlocal_returns_c0f949:
    .a8
    cmp #$20
    beq read_actor_animation_commands_and_native_nonlocal_returns_c0f932
    .a8
    cmp #$30
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f955
    lda $D0
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f96d
read_actor_animation_commands_and_native_nonlocal_returns_c0f955:
    stz a:$E01C,X
    stz a:$E011,X
    stz a:$E041,X
    stz a:$E042,X
    stz a:$E006,X
    stz a:$E007,X
    stz a:$E008,X
    brl restart_actor_frame_after_unwinding_reader_return
read_actor_animation_commands_and_native_nonlocal_returns_c0f96d:
    rep #$20
    lda a:$E018,X
    sta $00
    sec
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f976:
    .a8
    cmp #$FE
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f987
    lda a:$E190,X
    .a8
    and #$7B
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f9a7
read_actor_animation_commands_and_native_nonlocal_returns_c0f981:
    rep #$20
    inc $00
    sec
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f987:
    .a8
    cmp #$FB
    bcc read_actor_animation_commands_and_native_nonlocal_returns_c0f9c6
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f993
    jsl f:routine_02bf1d
    bra read_actor_animation_commands_and_native_nonlocal_returns_c0f981
read_actor_animation_commands_and_native_nonlocal_returns_c0f993:
    .a8
    cmp #$FC
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f9b0
    lda a:$E060,X
    .a8
    and #$40
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f9a7
    lda a:$E190,X
    .a8
    and #$03
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f9a7
    bra read_actor_animation_commands_and_native_nonlocal_returns_c0f981
read_actor_animation_commands_and_native_nonlocal_returns_c0f9a7:
    rep #$20
    lda $00
    sta a:$E016,X
    pla
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f9b0:
    lda a:$E060,X
    beq read_actor_animation_commands_and_native_nonlocal_returns_c0f981
    .a8
    cmp #$20
    bne read_actor_animation_commands_and_native_nonlocal_returns_c0f9a7
    rep #$20
    lda $00
    sta a:$E016,X
    pla
    jsl f:routine_018707
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f9c6:
    .a8
    cmp #$B0
    bcs read_actor_animation_commands_and_native_nonlocal_returns_c0f9d7
    jsl f:routine_01d5c0
    sep #$20
    lda a:$E000,X
    beq read_actor_animation_commands_and_native_nonlocal_returns_c0f9a7
    sec
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f9d7:
    .a8
    cmp #$F0
    bcs read_actor_animation_commands_and_native_nonlocal_returns_c0f9e1
    jsl f:routine_01d6dc
    sec
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f9e1:
    .a8
    cmp #$F8
    bcs read_actor_animation_commands_and_native_nonlocal_returns_c0f9eb
    jsl f:routine_01d52a
    sec
    rts
read_actor_animation_commands_and_native_nonlocal_returns_c0f9eb:
    jsl f:routine_01d48d
    sec
    rts
