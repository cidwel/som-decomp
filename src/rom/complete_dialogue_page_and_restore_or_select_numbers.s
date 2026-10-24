; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-line-completion.md.
.setcpu "65816"
.smart
.a8
.i16

mark_or_publish_dialogue_control_object = $1322
restore_suspended_dialogue_context_and_script_cursor = $0F2C

.segment "CODE"
.org $12BE
complete_dialogue_page_and_restore_or_select_numbers:
    stz a:$A15F
    stz a:$A15E
    lda f:$001D00
    .a8
    ora #$50
    sta f:$001D00
    lda f:$001D00
    .a8
    and #$80
    beq complete_dialogue_page_and_restore_or_select_numbers_c012ea
    lda f:$001D00
    .a8
    and #$3F
    sta f:$001D00
    .a8
    lda #$5A
    sta a:$A170
    stz a:$A160
    bra complete_dialogue_page_and_restore_or_select_numbers_c012f0
complete_dialogue_page_and_restore_or_select_numbers_c012ea:
    stz a:$A170
    jsr restore_suspended_dialogue_context_and_script_cursor
complete_dialogue_page_and_restore_or_select_numbers_c012f0:
    lda f:$001D05
    .a8
    cmp #$07
    bne complete_dialogue_page_and_restore_or_select_numbers_c012fb
    jsr mark_or_publish_dialogue_control_object
complete_dialogue_page_and_restore_or_select_numbers_c012fb:
    stz a:$A15D
    rts
