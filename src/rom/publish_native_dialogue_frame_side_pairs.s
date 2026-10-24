; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0

.segment "CODE"
.org $0C2A
publish_native_dialogue_frame_side_pairs:
    lda a:$A16C
    lsr
    bcc publish_native_dialogue_frame_side_pairs_c00c31
    inc
publish_native_dialogue_frame_side_pairs_c00c31:
    sta a:$A164
    lda a:$A166
    sta a:$A157
    lda a:$A165
    sta a:$A156
    .a8
    lda #$00
    xba
    lda a:$A24E
    rep #$20
    asl
    asl
    asl
    clc
    adc a:$A171
    tax
    sep #$20
    lda f:$C77259,X
    inx
    xba
    lda f:$C77259,X
    xba
    tax
    phx
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    inc a:$A156
publish_native_dialogue_frame_side_pairs_c00c6e:
    .i16
    ldx #$0118
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    lda a:$A164
    .a8
    cmp #$01
    bne publish_native_dialogue_frame_side_pairs_c00c87
    lda a:$A16C
    lsr
    bcs publish_native_dialogue_frame_side_pairs_c00c99
publish_native_dialogue_frame_side_pairs_c00c87:
    inc a:$A157
    inc a:$A156
    .i16
    ldx #$0118
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
publish_native_dialogue_frame_side_pairs_c00c99:
    inc a:$A157
    inc a:$A156
    dec a:$A164
    bne publish_native_dialogue_frame_side_pairs_c00c6e
    rep #$20
    pla
    pha
    .a16
    eor #$4000
    tax
    sep #$20
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    lda a:$A156
    sta a:$A165
    dec a:$A163
    bne publish_native_dialogue_frame_side_pairs_c00cc5
    brl publish_native_dialogue_frame_side_pairs_c00d47
publish_native_dialogue_frame_side_pairs_c00cc5:
    lda a:$A16C
    lsr
    bcc publish_native_dialogue_frame_side_pairs_c00ccc
    inc
publish_native_dialogue_frame_side_pairs_c00ccc:
    sta a:$A164
    lda a:$A167
    sta a:$A156
    lda a:$A166
    sta a:$A157
    rep #$20
    pla
    .a16
    eor #$8000
    tax
    phx
    sep #$20
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    dec a:$A156
publish_native_dialogue_frame_side_pairs_c00cf4:
    .i16
    ldx #$0118
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    dec a:$A156
    lda a:$A164
    .a8
    cmp #$01
    bne publish_native_dialogue_frame_side_pairs_c00d13
    lda a:$A16C
    lsr
    bcs publish_native_dialogue_frame_side_pairs_c00d25
publish_native_dialogue_frame_side_pairs_c00d13:
    .i16
    ldx #$0118
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    dec a:$A156
publish_native_dialogue_frame_side_pairs_c00d25:
    dec a:$A164
    bne publish_native_dialogue_frame_side_pairs_c00cf4
    rep #$20
    pla
    .a16
    eor #$4000
    tax
    sep #$20
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    lda a:$A156
    sta a:$A167
    dec a:$A163
    bne publish_native_dialogue_frame_side_pairs_c00d4a
publish_native_dialogue_frame_side_pairs_c00d47:
    inc a:$A15C
publish_native_dialogue_frame_side_pairs_c00d4a:
    inc a:$A171
    inc a:$A171
    rts
