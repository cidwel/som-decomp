; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0

.segment "CODE"
.org $0644
erase_native_dialogue_window_tile_pairs:
    lda a:$A16B
    lsr
    sta a:$A163
erase_native_dialogue_window_tile_pairs_c0064b:
    lda a:$A16C
    lsr
    bcc erase_native_dialogue_window_tile_pairs_c00652
    inc
erase_native_dialogue_window_tile_pairs_c00652:
    sta a:$A164
erase_native_dialogue_window_tile_pairs_c00655:
    .i16
    ldx #$0118
    lda a:$CFF8
    beq erase_native_dialogue_window_tile_pairs_c00660
    .i16
    ldx #$0000
erase_native_dialogue_window_tile_pairs_c00660:
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    lda a:$A164
    .a8
    cmp #$01
    bne erase_native_dialogue_window_tile_pairs_c00673
    lda a:$A16C
    lsr
    bcs erase_native_dialogue_window_tile_pairs_c00681
erase_native_dialogue_window_tile_pairs_c00673:
    .i16
    ldx #$0118
    lda a:$CFF8
    beq erase_native_dialogue_window_tile_pairs_c0067e
    .i16
    ldx #$0000
erase_native_dialogue_window_tile_pairs_c0067e:
    jsr exchange_dialogue_tilemap_entry_and_request_upload
erase_native_dialogue_window_tile_pairs_c00681:
    iny
    inc a:$A157
    dec a:$A164
    bne erase_native_dialogue_window_tile_pairs_c00655
    lda a:$A197
    sta a:$A157
    inc a:$A156
    dec a:$A163
    bne erase_native_dialogue_window_tile_pairs_c0064b
    lda a:$A157
    sta a:$A17D
    lda a:$A156
    sta a:$A17C
    inc a:$A15F
    rts
