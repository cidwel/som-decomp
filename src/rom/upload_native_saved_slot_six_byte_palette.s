; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $595C
upload_native_saved_slot_six_byte_palette:
    .a8
    lda #$19
    sta f:$002121
    .a8
    lda #$00
    xba
    .a8
    lda #$30
    tax
    .a8
    lda #$06
upload_native_saved_slot_six_byte_palette_c7596a:
    xba
    lda f:$D2DBC0,X
    sta f:$002122
    inx
    xba
    dec
    bne upload_native_saved_slot_six_byte_palette_c7596a
    rtl
