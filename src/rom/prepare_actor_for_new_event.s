; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

reset_actor_event_animation_and_motion = $F390

.segment "CODE"
.org $E88D
prepare_actor_for_new_event:
    rep #$10
    sep #$20
    stz $CC
    stz $CD
    stz $CE
    ldx $D4
    .i16
    ldy #$0000
    lda a:$E02C,X
    .a8
    and #$07
    beq prepare_actor_for_new_event_c1e8b3
    lsr
    beq prepare_actor_for_new_event_c1e8ab
    iny
    lsr
    beq prepare_actor_for_new_event_c1e8ab
    iny
prepare_actor_for_new_event_c1e8ab:
    lda a:$00D9,Y
    .a8
    ora #$80
    sta a:$00D9,Y
prepare_actor_for_new_event_c1e8b3:
    lda $FF
    bne prepare_actor_for_new_event_c1e8c2
    rep #$20
    .a16
    lda #$0000
    sta a:$E006,X
    sta a:$E008,X
prepare_actor_for_new_event_c1e8c2:
    jsr reset_actor_event_animation_and_motion
    plx
    rts
