; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

consume_body_damage_or_parent_phase15_and_enter_hurt = $4DB9
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $4C74
retract_body_segments_and_choose_next_phase:
    ldx $87
    lda a:$00B0,X
    tax
    inc a:$00BC,X
    ldx $87
    jsr consume_body_damage_or_parent_phase15_and_enter_hurt
    bcs retract_body_segments_and_choose_next_phase_c24ccf
    lda a:$00B2,X
    beq retract_body_segments_and_choose_next_phase_c24cd1
    lda a:$0096,X
    .a16
    cmp #$0004
    bne retract_body_segments_and_choose_next_phase_c24ccf
    sep #$20
    lda a:$F804,Y
    .a8
    eor #$40
    sta a:$F804,Y
    rep #$20
    lda a:$00B8,X
    sec
    .a16
    sbc #$0004
    sta a:$00B8,X
    tay
    lda a:$0000,Y
    .a16
    and #$000F
    sep #$20
    .a8
    cmp #$02
    beq retract_body_segments_and_choose_next_phase_c24cbd
    lsr
    tax
    lda f:$DCE637,X
    sta a:$0000,Y
retract_body_segments_and_choose_next_phase_c24cbd:
    rep #$20
    ldx $87
    dec a:$00B2,X
    stz a:$0096,X
    lda $8B
    xba
    lsr
    tax
    dec a:$F800,X
retract_body_segments_and_choose_next_phase_c24ccf:
    clc
    rts
retract_body_segments_and_choose_next_phase_c24cd1:
    lda a:$00BC,X
    beq retract_body_segments_and_choose_next_phase_c24ce4
    .a16
    lda #$0078
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0002
    sta a:$0094,X
    clc
    rts
retract_body_segments_and_choose_next_phase_c24ce4:
    .a16
    lda #$0008
    sta a:$0094,X
    stz a:$0096,X
    clc
    rts
