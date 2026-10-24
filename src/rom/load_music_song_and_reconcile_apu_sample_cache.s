; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-music-loader.md.
.setcpu "65816"
.smart
.a8
.i16

configure_music_echo_and_evict_samples_above_echo_limit = $060A
routine_c3018d = $018D
transfer_fixed_extra_music_data_to_apu_address_2c00 = $067E

.segment "CODE"
.org $0198
load_music_song_and_reconcile_apu_sample_cache:
    sep #$20
    xba
    lda $02
    .a8
    and #$0F
    pha
    lda $01
    pha
    plx
    cpx $05
    beq routine_c3018d
    lda a:$2142
    beq load_music_song_and_reconcile_apu_sample_cache_c301ca
    lda $02
    .a8
    and #$F0
    beq load_music_song_and_reconcile_apu_sample_cache_c301ca
    sta a:$2141
    .a8
    lda #$83
load_music_song_and_reconcile_apu_sample_cache_c301b8:
    cmp a:$2140
    beq load_music_song_and_reconcile_apu_sample_cache_c301b8
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c301c0:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c301c0
    .a8
    lda #$00
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c301ca:
    lda $05
    bmi load_music_song_and_reconcile_apu_sample_cache_c301d4
    sta $09
    ldx $06
    stx $0A
load_music_song_and_reconcile_apu_sample_cache_c301d4:
    lda $01
    sta a:$2141
    sta $05
    lda $02
    sta a:$2142
    .a8
    and #$0F
    sta $06
    lda $03
    sta a:$2143
    sta $07
load_music_song_and_reconcile_apu_sample_cache_c301eb:
    lda a:$2141
    bne load_music_song_and_reconcile_apu_sample_cache_c301eb
    xba
load_music_song_and_reconcile_apu_sample_cache_c301f1:
    cmp a:$2140
    beq load_music_song_and_reconcile_apu_sample_cache_c301f1
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c301f9:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c301f9
    inc
    xba
    jsr configure_music_echo_and_evict_samples_above_echo_limit
    .a8
    lda #$02
    sta a:$2141
    lda $F3
    beq load_music_song_and_reconcile_apu_sample_cache_c3020f
    jsr transfer_fixed_extra_music_data_to_apu_address_2c00
load_music_song_and_reconcile_apu_sample_cache_c3020f:
    .i16
    ldx #$1A00
    stx a:$2142
    xba
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c30219:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c30219
    rep #$20
    lda $05
    .a16
    and #$00FF
    pha
    asl
    sta $EA
    pla
    clc
    adc $EA
    tax
    sep #$20
    lda f:$C33D39,X
    sta $14
    lda f:$C33D3A,X
    sta $15
    lda f:$C33D3B,X
    sta $16
    ldy $14
    stz $14
    stz $15
    lda [$14],Y
    xba
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c30250
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c30250:
    lda [$14],Y
    pha
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c30258
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c30258:
    xba
    pha
    plx
    stz $F3
    .i16
    cpx #$1200
    bcc load_music_song_and_reconcile_apu_sample_cache_c30264
    inc $F3
load_music_song_and_reconcile_apu_sample_cache_c30264:
    .a8
    lda #$80
    xba
load_music_song_and_reconcile_apu_sample_cache_c30267:
    lda [$14],Y
    sta a:$2142
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c30271
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c30271:
    lda [$14],Y
    sta a:$2143
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c3027b
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c3027b:
    xba
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c3027f:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c3027f
    inc
    bne load_music_song_and_reconcile_apu_sample_cache_c30288
    inc
load_music_song_and_reconcile_apu_sample_cache_c30288:
    xba
    dex
    dex
    bpl load_music_song_and_reconcile_apu_sample_cache_c30267
    rep #$20
    .i16
    ldx #$0000
load_music_song_and_reconcile_apu_sample_cache_c30292:
    stz $8A,X
    stz $CA,X
    inx
    inx
    .i16
    cpx #$0020
    bne load_music_song_and_reconcile_apu_sample_cache_c30292
    lda $04
    .a16
    and #$FF00
    lsr
    lsr
    lsr
    tax
    clc
    .a16
    adc #$0020
    sta $12
    .a16
    lda #$1EAA
    sta $14
    .a16
    lda #$1ECA
    sta $16
load_music_song_and_reconcile_apu_sample_cache_c302b6:
    lda f:$C33F22,X
    sta ($14)
    inc $14
    inc $14
    .i16
    ldy #$0000
load_music_song_and_reconcile_apu_sample_cache_c302c3:
    cmp a:$1E28,Y
    beq load_music_song_and_reconcile_apu_sample_cache_c302d7
    iny
    iny
    .i16
    cpy #$0020
    bne load_music_song_and_reconcile_apu_sample_cache_c302c3
    sta ($16)
    inc $16
    inc $16
    bra load_music_song_and_reconcile_apu_sample_cache_c302da
load_music_song_and_reconcile_apu_sample_cache_c302d7:
    sta a:$1E8A,Y
load_music_song_and_reconcile_apu_sample_cache_c302da:
    inx
    inx
    cpx $12
    bne load_music_song_and_reconcile_apu_sample_cache_c302b6
    lda $CA
    bne load_music_song_and_reconcile_apu_sample_cache_c302e7
    jmp load_music_song_and_reconcile_apu_sample_cache_c304c2
load_music_song_and_reconcile_apu_sample_cache_c302e7:
    stz $17
    sep #$20
    .i16
    ldx #$0000
load_music_song_and_reconcile_apu_sample_cache_c302ee:
    lda $CA,X
    beq load_music_song_and_reconcile_apu_sample_cache_c30333
    phx
    dec
    rep #$20
    .a16
    and #$00FF
    pha
    asl
    sta $EA
    pla
    clc
    adc $EA
    tax
    sep #$20
    lda f:$C33DF9,X
    sta $14
    lda f:$C33DFA,X
    sta $15
    lda f:$C33DFB,X
    sta $16
    ldy $14
    stz $14
    stz $15
    lda [$14],Y
    clc
    adc $17
    sta $17
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c30328
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c30328:
    lda [$14],Y
    adc $18
    sta $18
    plx
    inx
    inx
    bra load_music_song_and_reconcile_apu_sample_cache_c302ee
load_music_song_and_reconcile_apu_sample_cache_c30333:
    .i16
    ldx #$0000
    rep #$20
load_music_song_and_reconcile_apu_sample_cache_c30338:
    lda $28,X
    beq load_music_song_and_reconcile_apu_sample_cache_c30340
    inx
    inx
    bra load_music_song_and_reconcile_apu_sample_cache_c30338
load_music_song_and_reconcile_apu_sample_cache_c30340:
    lda $48,X
    clc
    adc $17
    bcs load_music_song_and_reconcile_apu_sample_cache_c3034e
    cmp $F1
    bcs load_music_song_and_reconcile_apu_sample_cache_c3034e
    jmp load_music_song_and_reconcile_apu_sample_cache_c30400
load_music_song_and_reconcile_apu_sample_cache_c3034e:
    .i16
    ldx #$001E
load_music_song_and_reconcile_apu_sample_cache_c30351:
    lda $88,X
    bne load_music_song_and_reconcile_apu_sample_cache_c30359
    dex
    dex
    bne load_music_song_and_reconcile_apu_sample_cache_c30351
load_music_song_and_reconcile_apu_sample_cache_c30359:
    stx $24
    .i16
    ldx #$0000
load_music_song_and_reconcile_apu_sample_cache_c3035e:
    lda $8A,X
    beq load_music_song_and_reconcile_apu_sample_cache_c30369
    inx
    inx
    .i16
    cpx #$0020
    bne load_music_song_and_reconcile_apu_sample_cache_c3035e
load_music_song_and_reconcile_apu_sample_cache_c30369:
    cpx $24
    bne load_music_song_and_reconcile_apu_sample_cache_c30379
load_music_song_and_reconcile_apu_sample_cache_c3036d:
    stz $28,X
    inx
    inx
    .i16
    cpx #$0020
    bne load_music_song_and_reconcile_apu_sample_cache_c3036d
    jmp load_music_song_and_reconcile_apu_sample_cache_c30400
load_music_song_and_reconcile_apu_sample_cache_c30379:
    sep #$20
    .a8
    lda #$07
    sta a:$2141
    stz $10
    .i16
    ldy #$0000
    rep #$20
load_music_song_and_reconcile_apu_sample_cache_c30387:
    lda a:$1E8A,Y
    beq load_music_song_and_reconcile_apu_sample_cache_c30394
load_music_song_and_reconcile_apu_sample_cache_c3038c:
    iny
    iny
    cpy $24
    bne load_music_song_and_reconcile_apu_sample_cache_c30387
    bra load_music_song_and_reconcile_apu_sample_cache_c303f6
load_music_song_and_reconcile_apu_sample_cache_c30394:
    tyx
    bra load_music_song_and_reconcile_apu_sample_cache_c3039b
load_music_song_and_reconcile_apu_sample_cache_c30397:
    lda $8A,X
    bne load_music_song_and_reconcile_apu_sample_cache_c303a3
load_music_song_and_reconcile_apu_sample_cache_c3039b:
    inx
    inx
    cpx $24
    bne load_music_song_and_reconcile_apu_sample_cache_c30397
    bra load_music_song_and_reconcile_apu_sample_cache_c303f6
load_music_song_and_reconcile_apu_sample_cache_c303a3:
    stz $28,X
    stz $8A,X
    sta a:$1E28,Y
    lda $48,X
    sta a:$2142
    sep #$20
    lda $10
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c303b6:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c303b6
    inc $10
    rep #$20
    lda a:$1E48,Y
    sta a:$2142
    sep #$20
    lda $10
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c303cc:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c303cc
    inc $10
    rep #$20
    lda $6A,X
    sta a:$2142
    sta a:$1E6A,Y
    clc
    adc a:$1E48,Y
    sta a:$1E4A,Y
    sep #$20
    lda $10
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c303eb:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c303eb
    inc $10
    rep #$20
    bra load_music_song_and_reconcile_apu_sample_cache_c3038c
load_music_song_and_reconcile_apu_sample_cache_c303f6:
    tyx
load_music_song_and_reconcile_apu_sample_cache_c303f7:
    stz $28,X
    inx
    inx
    .i16
    cpx #$0020
    bne load_music_song_and_reconcile_apu_sample_cache_c303f7
load_music_song_and_reconcile_apu_sample_cache_c30400:
    sep #$20
    .a8
    lda #$03
    sta a:$2141
    .i16
    ldx #$0000
load_music_song_and_reconcile_apu_sample_cache_c3040a:
    lda $28,X
    beq load_music_song_and_reconcile_apu_sample_cache_c30412
    inx
    inx
    bra load_music_song_and_reconcile_apu_sample_cache_c3040a
load_music_song_and_reconcile_apu_sample_cache_c30412:
    stx $24
    lda $48,X
    sta a:$2142
    lda $49,X
    sta a:$2143
    .a8
    lda #$00
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c30423:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c30423
    inc
    sta $10
    .i16
    ldx #$0000
load_music_song_and_reconcile_apu_sample_cache_c3042e:
    sep #$20
    lda $CA,X
    bne load_music_song_and_reconcile_apu_sample_cache_c30437
    jmp load_music_song_and_reconcile_apu_sample_cache_c304c2
load_music_song_and_reconcile_apu_sample_cache_c30437:
    ldy $24
    sta a:$1E28,Y
    phx
    dec
    rep #$20
    .a16
    and #$00FF
    pha
    asl
    sta $EA
    pla
    clc
    adc $EA
    tax
    sep #$20
    lda f:$C33DF9,X
    sta $14
    lda f:$C33DFA,X
    sta $15
    lda f:$C33DFB,X
    sta $16
    ldy $14
    stz $14
    stz $15
    lda [$14],Y
    xba
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c3046e
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c3046e:
    lda [$14],Y
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c30475
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c30475:
    xba
    rep #$20
    pha
    ldx $24
    sta $6A,X
    clc
    adc $48,X
    sta $4A,X
    inx
    inx
    stx $24
    plx
    sep #$20
load_music_song_and_reconcile_apu_sample_cache_c30489:
    lda [$14],Y
    sta a:$2141
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c30493
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c30493:
    lda [$14],Y
    sta a:$2142
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c3049d
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c3049d:
    lda [$14],Y
    sta a:$2143
    iny
    bne load_music_song_and_reconcile_apu_sample_cache_c304a7
    inc $16
load_music_song_and_reconcile_apu_sample_cache_c304a7:
    lda $10
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c304ac:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c304ac
    inc $10
    bne load_music_song_and_reconcile_apu_sample_cache_c304b7
    inc $10
load_music_song_and_reconcile_apu_sample_cache_c304b7:
    dex
    dex
    dex
    bne load_music_song_and_reconcile_apu_sample_cache_c30489
    plx
    inx
    inx
    brl load_music_song_and_reconcile_apu_sample_cache_c3042e
load_music_song_and_reconcile_apu_sample_cache_c304c2:
    rep #$20
    lda $AA
    bne load_music_song_and_reconcile_apu_sample_cache_c304cb
    jmp load_music_song_and_reconcile_apu_sample_cache_c30592
load_music_song_and_reconcile_apu_sample_cache_c304cb:
    .a16
    lda #$1EAA
    sta $14
    .a16
    lda #$1F00
    sta $16
    .a16
    lda #$1F40
    sta $18
    .a16
    lda #$1FC0
    sta $1A
load_music_song_and_reconcile_apu_sample_cache_c304df:
    lda ($14)
    beq load_music_song_and_reconcile_apu_sample_cache_c30520
    inc $14
    inc $14
    .i16
    ldy #$0000
load_music_song_and_reconcile_apu_sample_cache_c304ea:
    cmp a:$1E28,Y
    beq load_music_song_and_reconcile_apu_sample_cache_c304f3
    iny
    iny
    bra load_music_song_and_reconcile_apu_sample_cache_c304ea
load_music_song_and_reconcile_apu_sample_cache_c304f3:
    dec
    asl
    tax
    lda f:$C33E9E,X
    sta ($16)
    inc $16
    inc $16
    lda a:$1E48,Y
    sta ($18)
    inc $18
    inc $18
    clc
    adc f:$C33E5C,X
    sta ($18)
    inc $18
    inc $18
    lda f:$C33EE0,X
    sta ($1A)
    inc $1A
    inc $1A
    bra load_music_song_and_reconcile_apu_sample_cache_c304df
load_music_song_and_reconcile_apu_sample_cache_c30520:
    sep #$20
    .a8
    lda #$02
    sta a:$2141
    .i16
    ldx #$1F00
    phx
    pld
    .i16
    ldx #$1840
    stx a:$2142
    .a8
    lda #$00
    .i16
    ldx #$FFFE
    bra load_music_song_and_reconcile_apu_sample_cache_c3053e
load_music_song_and_reconcile_apu_sample_cache_c30539:
    ldy $00,X
    sty a:$2142
load_music_song_and_reconcile_apu_sample_cache_c3053e:
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c30541:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c30541
    inc
    inx
    inx
    .i16
    cpx #$0040
    bne load_music_song_and_reconcile_apu_sample_cache_c30539
    .i16
    ldx #$1980
    stx a:$2142
    .a8
    lda #$00
    .i16
    ldx #$FFFE
    bra load_music_song_and_reconcile_apu_sample_cache_c30560
load_music_song_and_reconcile_apu_sample_cache_c3055b:
    ldy $40,X
    sty a:$2142
load_music_song_and_reconcile_apu_sample_cache_c30560:
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c30563:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c30563
    inc
    inx
    inx
    .i16
    cpx #$0080
    bne load_music_song_and_reconcile_apu_sample_cache_c3055b
    .i16
    ldx #$18C0
    stx a:$2142
    .a8
    lda #$00
    .i16
    ldx #$FFFE
    bra load_music_song_and_reconcile_apu_sample_cache_c30582
load_music_song_and_reconcile_apu_sample_cache_c3057d:
    ldy $C0,X
    sty a:$2142
load_music_song_and_reconcile_apu_sample_cache_c30582:
    sta a:$2140
load_music_song_and_reconcile_apu_sample_cache_c30585:
    cmp a:$2140
    bne load_music_song_and_reconcile_apu_sample_cache_c30585
    inc
    inx
    inx
    .i16
    cpx #$0040
    bne load_music_song_and_reconcile_apu_sample_cache_c3057d
load_music_song_and_reconcile_apu_sample_cache_c30592:
    sep #$20
    .a8
    lda #$00
    sta a:$2141
    sta a:$2140
    jmp routine_c3018d
