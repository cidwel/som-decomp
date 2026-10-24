; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

copy_requested_dialogue_rows_to_upload_buffer = $14C6
set_dialogue_graphics_transfer_size_preserving_status = $1936

.segment "CODE"
.org $1479
copy_dialogue_font_page_and_publish_transfer:
    .a8
    lda #$38
    sta a:$A171
    .i16
    ldy #$9000
    .i16
    ldx #$9400
    jsr copy_requested_dialogue_rows_to_upload_buffer
    rep #$20
    .a16
    lda #$4910
    sta f:$001D06
    clc
    .a16
    adc #$01C0
    sta a:$A18C
    .a16
    lda #$0000
    sta a:$A18E
    .a16
    lda #$0380
    jsr set_dialogue_graphics_transfer_size_preserving_status
    .a16
    lda #$9000
    sta a:$A189
    lda a:$A162
    .a16
    and #$00FF
    .a16
    cmp #$0002
    bne copy_dialogue_font_page_and_publish_transfer_c014c0
    .i16
    ldx #$4F00
    stx a:$1D06
    .a16
    lda #$0200
    jsr set_dialogue_graphics_transfer_size_preserving_status
copy_dialogue_font_page_and_publish_transfer_c014c0:
    sep #$20
    stz a:$A181
    rts
