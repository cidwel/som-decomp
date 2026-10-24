; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

assign_large_object_palette_rows = $E2A8

.segment "CODE"
.org $E1A8
prepare_map_object_slots_and_buffers:
    rep #$30
    lda a:$E802
    sta $0D
    .a16
    lda #$0000
    .i16
    ldx #$11FE
prepare_map_object_slots_and_buffers_c0e1b5:
    sta a:$E600,X
    sta a:$E600,X
    dex
    dex
    bpl prepare_map_object_slots_and_buffers_c0e1b5
    .i16
    ldx #$00FE
prepare_map_object_slots_and_buffers_c0e1c2:
    sta a:$C800,X
    sta a:$C900,X
    sta a:$CA00,X
    dex
    dex
    bpl prepare_map_object_slots_and_buffers_c0e1c2
    .i16
    ldx #$003E
prepare_map_object_slots_and_buffers_c0e1d2:
    sta a:$CB00,X
    dex
    dex
    bpl prepare_map_object_slots_and_buffers_c0e1d2
    sep #$20
    bit $ED
    rep #$20
    bpl prepare_map_object_slots_and_buffers_c0e238
    .a16
    lda #$0E60
    sta a:$E66E
    .a16
    lda #$0EC0
    sta a:$E86E
    .a16
    lda #$0F20
    sta a:$EA6E
    .a16
    lda #$0D60
    sta a:$E66C
    .a16
    lda #$0DB0
    sta a:$E86C
    .a16
    lda #$0E00
    sta a:$EA6C
    .a16
    lda #$0A40
    eor $98
    sta a:$E68A
    .a16
    lda #$08C8
    eor $98
    sta a:$E686
    .a16
    lda #$0C68
    eor $98
    sta a:$E88A
    .a16
    lda #$08EC
    eor $98
    sta a:$E886
    .a16
    lda #$0EA0
    eor $98
    sta a:$EA8A
    .a16
    lda #$0920
    eor $98
    sta a:$EA86
    jmp assign_large_object_palette_rows
prepare_map_object_slots_and_buffers_c0e238:
    .a16
    lda #$0E60
    sta a:$E66E
    .a16
    lda #$0E80
    sta a:$E86E
    .a16
    lda #$0EA0
    sta a:$EA6E
    .a16
    lda #$0EC0
    sta a:$EC6E
    .a16
    lda #$0EE0
    sta a:$EE6E
    .a16
    lda #$0F00
    sta a:$F06E
    .a16
    lda #$0F20
    sta a:$F26E
    .a16
    lda #$0F40
    sta a:$F46E
    .a16
    lda #$0F60
    sta a:$F66E
    .a16
    lda #$0840
    eor $98
    sta a:$E68A
    clc
    .a16
    adc #$0008
    sta a:$E88A
    .a16
    adc #$0018
    sta a:$EA8A
    .a16
    adc #$0008
    sta a:$EC8A
    .a16
    adc #$0018
    sta a:$EE8A
    .a16
    adc #$0008
    sta a:$F08A
    .a16
    adc #$0018
    sta a:$F28A
    .a16
    adc #$0008
    sta a:$F48A
    .a16
    adc #$0018
    sta a:$F68A
    rts
