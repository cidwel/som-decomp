; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0

.segment "CODE"
.org $0B4F
publish_native_dialogue_frame_border_rows:
    lda a:$A166
    sta a:$A157
    lda a:$A165
    sta a:$A156
    lda a:$A16C
    inc
    inc
    lsr
    bcc publish_native_dialogue_frame_border_rows_c00b64
    inc
publish_native_dialogue_frame_border_rows_c00b64:
    sta a:$A164
    .a8
    lda #$00
    xba
    lda a:$A24E
    rep #$20
    asl
    sta a:$A173
    asl
    asl
    asl
    asl
    sec
    sbc a:$A173
    tax
    sep #$20
    phx
publish_native_dialogue_frame_border_rows_c00b7f:
    lda f:$C77169,X
    xba
    inx
    lda f:$C77169,X
    inx
    xba
    txy
    tax
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    tyx
    inc a:$A157
    dec a:$A164
    bne publish_native_dialogue_frame_border_rows_c00b7f
    lda a:$A16C
    inc
    inc
    lsr
    sta a:$A164
    bcc publish_native_dialogue_frame_border_rows_c00ba6
    dex
    dex
publish_native_dialogue_frame_border_rows_c00ba6:
    dex
publish_native_dialogue_frame_border_rows_c00ba7:
    lda f:$C77169,X
    .a8
    eor #$40
    xba
    dex
    lda f:$C77169,X
    dex
    txy
    tax
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    tyx
    inc a:$A157
    dec a:$A164
    bne publish_native_dialogue_frame_border_rows_c00ba7
    lda a:$A16C
    inc
    inc
    lsr
    bcc publish_native_dialogue_frame_border_rows_c00bcb
    inc
publish_native_dialogue_frame_border_rows_c00bcb:
    sta a:$A164
    inc a:$A156
    .i16
    ldx #$0000
    lda a:$A166
    sta a:$A157
    plx
publish_native_dialogue_frame_border_rows_c00bdb:
    lda f:$C77169,X
    xba
    inx
    lda f:$C77169,X
    inx
    .a8
    eor #$80
    txy
    xba
    tax
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    tyx
    inc a:$A157
    dec a:$A164
    bne publish_native_dialogue_frame_border_rows_c00bdb
    lda a:$A16C
    inc
    inc
    lsr
    sta a:$A164
    bcc publish_native_dialogue_frame_border_rows_c00c04
    dex
    dex
publish_native_dialogue_frame_border_rows_c00c04:
    dex
publish_native_dialogue_frame_border_rows_c00c05:
    lda f:$C77169,X
    .a8
    eor #$C0
    xba
    dex
    lda f:$C77169,X
    dex
    txy
    tax
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    tyx
    inc a:$A157
    dec a:$A164
    bne publish_native_dialogue_frame_border_rows_c00c05
    stz a:$A171
    stz a:$A172
    inc a:$A15C
    rts
