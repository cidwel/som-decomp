; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-line-completion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $126F
complete_dialogue_line_and_select_next_render_phase:
    stz a:$A15D
    stz a:$A16D
    .i16
    ldx #$9000
    stx a:$A189
    lda f:$001D00
    .a8
    bit #$80
    bne complete_dialogue_line_and_select_next_render_phase_c0129e
    .a8
    and #$01
    beq complete_dialogue_line_and_select_next_render_phase_c012a8
    lda f:$001D00
    .a8
    and #$FE
    sta f:$001D00
    lda a:$A16B
    lsr
    dec
    cmp a:$A180
    bne complete_dialogue_line_and_select_next_render_phase_c012a5
    sta a:$A180
complete_dialogue_line_and_select_next_render_phase_c0129e:
    .a8
    lda #$09
    sta a:$A15D
    bra complete_dialogue_line_and_select_next_render_phase_c012bd
complete_dialogue_line_and_select_next_render_phase_c012a5:
    inc a:$A180
complete_dialogue_line_and_select_next_render_phase_c012a8:
    stz a:$A170
    lda f:$001D05
    .a8
    cmp #$07
    bne complete_dialogue_line_and_select_next_render_phase_c012bd
    .a8
    lda #$09
    sta a:$A15D
    .a8
    lda #$53
    sta a:$A170
complete_dialogue_line_and_select_next_render_phase_c012bd:
    rts
