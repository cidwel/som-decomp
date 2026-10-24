; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16

restore_suspended_dialogue_context_and_script_cursor = $0F2C

.segment "CODE"
.org $08C3
finish_dialogue_window_closing_and_restore_suspended_context:
    lda a:$A162
    .a8
    cmp #$02
    beq finish_dialogue_window_closing_and_restore_suspended_context_c008d7
    .i16
    ldy #$002C
    .i16
    ldx #$0000
finish_dialogue_window_closing_and_restore_suspended_context_c008d0:
    stz a:$9C00,X
    inx
    dey
    bne finish_dialogue_window_closing_and_restore_suspended_context_c008d0
finish_dialogue_window_closing_and_restore_suspended_context_c008d7:
    stz a:$A15E
    stz a:$A16D
    stz a:$A170
    lda f:$001D04
    .a8
    bit #$80
    bne finish_dialogue_window_closing_and_restore_suspended_context_c008f5
    rep #$20
    lda f:$001D01
    inc
    sta f:$001D01
    sep #$20
finish_dialogue_window_closing_and_restore_suspended_context_c008f5:
    lda f:$001D00
    .a8
    ora #$80
    sta f:$001D00
    lda a:$A162
    .a8
    cmp #$02
    bne finish_dialogue_window_closing_and_restore_suspended_context_c0090b
    .a8
    lda #$01
    trb a:$A187
finish_dialogue_window_closing_and_restore_suspended_context_c0090b:
    jsr restore_suspended_dialogue_context_and_script_cursor
    rts
