; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-audio-boot.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c30175 = $0175
routine_c3018d = $018D

.segment "CODE"
.org $002C
upload_six_spc_blocks_or_reset_ready_audio_metadata:
    phb
    phd
    php
    rep #$20
    rep #$10
    pha
    phx
    phy
    sep #$20
    .a8
    lda #$00
    pha
    plb
    .i16
    ldx #$1E00
    phx
    pld
    .i16
    ldx #$BBAA
    .i16
    ldy #$0800
upload_six_spc_blocks_or_reset_ready_audio_metadata_c30047:
    cpx a:$2140
    beq upload_six_spc_blocks_or_reset_ready_audio_metadata_c3007e
    dey
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c30047
    ldy $F8
    beq upload_six_spc_blocks_or_reset_ready_audio_metadata_c3007e
    cpy $48
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c3007e
    .a8
    lda #$F0
    cmp $00
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c3007e
    .a8
    lda #$08
    sta a:$2141
    .a8
    lda #$00
    sta a:$2140
    .i16
    ldx #$00F0
upload_six_spc_blocks_or_reset_ready_audio_metadata_c3006a:
    sta a:$1DFF,X
    dex
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c3006a
    ldy $F8
    sty $48
    dec
    sta $05
    .a8
    lda #$F0
    sta $00
    jmp routine_c30175
upload_six_spc_blocks_or_reset_ready_audio_metadata_c3007e:
    cpx a:$2140
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c3007e
    .i16
    ldx #$0000
    lda f:$C30014
    sta a:$2142
    lda f:$C30015
    sta a:$2143
    .a8
    lda #$CC
    sta a:$2141
    sta a:$2140
upload_six_spc_blocks_or_reset_ready_audio_metadata_c3009c:
    cmp a:$2140
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c3009c
upload_six_spc_blocks_or_reset_ready_audio_metadata_c300a1:
    .a8
    lda #$00
    xba
    lda f:$C30008,X
    sta $14
    lda f:$C30009,X
    sta $15
    .a8
    lda #$C3
    sta $16
    .i16
    ldy #$0000
    lda [$14],Y
    clc
    .a8
    adc #$02
    sta $10
    iny
    lda [$14],Y
    .a8
    adc #$00
    sta $11
    iny
upload_six_spc_blocks_or_reset_ready_audio_metadata_c300c6:
    lda [$14],Y
    sta a:$2141
    xba
    sta a:$2140
upload_six_spc_blocks_or_reset_ready_audio_metadata_c300cf:
    cmp a:$2140
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c300cf
    inc
    xba
    iny
    cpy $10
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c300c6
    xba
    inc
    inc
    inc
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c300e2
    inc
upload_six_spc_blocks_or_reset_ready_audio_metadata_c300e2:
    inx
    inx
    .i16
    cpx #$000C
    beq upload_six_spc_blocks_or_reset_ready_audio_metadata_c30106
    xba
    lda f:$C30014,X
    sta a:$2142
    lda f:$C30015,X
    sta a:$2143
    xba
    sta a:$2141
    sta a:$2140
upload_six_spc_blocks_or_reset_ready_audio_metadata_c300ff:
    cmp a:$2140
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c300ff
    bra upload_six_spc_blocks_or_reset_ready_audio_metadata_c300a1
upload_six_spc_blocks_or_reset_ready_audio_metadata_c30106:
    .i16
    ldy #$0200
    sty a:$2142
    xba
    .a8
    lda #$00
    sta a:$2141
    xba
    sta a:$2140
upload_six_spc_blocks_or_reset_ready_audio_metadata_c30116:
    cmp a:$2140
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c30116
    xba
    sta a:$2140
    .i16
    ldx #$0100
upload_six_spc_blocks_or_reset_ready_audio_metadata_c30122:
    sta a:$1DFF,X
    dex
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c30122
    .a8
    lda #$FF
    sta $05
    rep #$20
    lda f:$C31AE2
    clc
    .a16
    adc #$4800
    sta $F8
    sta $48
    .i16
    ldx #$0800
upload_six_spc_blocks_or_reset_ready_audio_metadata_c3013d:
    dex
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c3013d
    sep #$20
    .a8
    lda #$00
    sta $FA
    .a8
    lda #$C3
    sta $FB
    .a8
    lda #$02
    sta $F0
    bne upload_six_spc_blocks_or_reset_ready_audio_metadata_c30151
    inc
upload_six_spc_blocks_or_reset_ready_audio_metadata_c30151:
    asl
    asl
    asl
    .a8
    eor #$FF
    inc
    clc
    .a8
    adc #$FA
    sta $F2
    stz $F1
    bra routine_c3018d
