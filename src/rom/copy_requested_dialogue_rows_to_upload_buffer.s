; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $14C6
copy_requested_dialogue_rows_to_upload_buffer:
copy_requested_dialogue_rows_to_upload_buffer_c014c6:
    .a8
    lda #$10
copy_requested_dialogue_rows_to_upload_buffer_c014c8:
    xba
    lda a:$0000,Y
    sta a:$0000,X
    inx
    iny
    xba
    dec
    bne copy_requested_dialogue_rows_to_upload_buffer_c014c8
    dec a:$A171
    bne copy_requested_dialogue_rows_to_upload_buffer_c014c6
    rts
