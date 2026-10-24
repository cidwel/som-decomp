; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_piece_work_cache = $CBC2
decode_map_piece_body = $CD93

.segment "CODE"
.org $CBD1
load_conditional_map_piece:
    jsr clear_map_piece_work_cache
    sep #$30
    stz $16
    stz $17
    .i8
    ldy #$00
    lda [$20],Y
    .a8
    cmp #$FE
    bcc load_conditional_map_piece_c0cc2c
    inc $20
    bne load_conditional_map_piece_c0cbe8
    inc $21
load_conditional_map_piece_c0cbe8:
    .a8
    cmp #$FF
    beq load_conditional_map_piece_c0cc08
    .i8
    ldy #$03
    lda [$20],Y
    lsr
    sta $9E
    iny
    lda [$20],Y
    lsr
    sta $9F
    xba
    lda $9E
    asl
    rep #$20
    lsr
    sta $C8
    sep #$20
    stz $13
    bra load_conditional_map_piece_c0cc28
load_conditional_map_piece_c0cc08:
    .a8
    lda #$40
    sta $13
    .i8
    ldy #$03
    lda [$20],Y
    lsr
    sta $A2
    iny
    lda [$20],Y
    lsr
    sta $A3
    .a8
    ora #$80
    xba
    lda $A2
    asl
    rep #$20
    lsr
    sta $CA
    sep #$20
    inc $B9
load_conditional_map_piece_c0cc28:
    .i8
    ldy #$00
    lda [$20],Y
load_conditional_map_piece_c0cc2c:
    tax
    lda f:$7ECF00,X
    sta $00
    iny
    lda [$20],Y
    pha
    .a8
    and #$0F
    sta $01
    pla
    lsr
    lsr
    lsr
    lsr
    sta $02
    lda $00
    cmp $02
    bcs load_conditional_map_piece_c0cc49
load_conditional_map_piece_c0cc48:
    rts
load_conditional_map_piece_c0cc49:
    cmp $01
    beq load_conditional_map_piece_c0cc4f
    bcs load_conditional_map_piece_c0cc48
load_conditional_map_piece_c0cc4f:
    iny
    lda $13
    .a8
    and #$40
    sta $13
    lda [$20],Y
    sta $00
    iny
    lda [$20],Y
    lsr
    ror $01
    asl
    sta $12
    iny
    lda [$20],Y
    lsr
    rol $01
    rol $01
    lsr
    ora $13
    sta $13
    ror $12
    rep #$20
    lda $00
    .a16
    and #$03FF
    .i8
    ldx #$CD
    cmp f:$CD0000
    bcc load_conditional_map_piece_c0cc91
    inx
    cmp f:$CD0002
    bcc load_conditional_map_piece_c0cc91
    inx
    cmp f:$CD0004
    bcc load_conditional_map_piece_c0cc91
    .i8
    ldx #$CC
load_conditional_map_piece_c0cc91:
    stx $1F
    rep #$10
    asl
    tax
    lda f:$CD0004,X
    sta $1D
    sep #$30
    .i8
    ldy #$00
    lda [$1D],Y
    lsr
    ror $00
    inc
    sta $14
    iny
    lda [$1D],Y
    iny
    lsr
    rol $00
    rol $00
    inc
    sta $15
    lda $B9
    bne load_conditional_map_piece_c0ccdf
    lda $9C
    bne load_conditional_map_piece_c0cd03
    lda $14
    sta $9C
    lda $15
    sta $9D
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $C2
    lda $9C
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $C0
    sep #$20
    bra load_conditional_map_piece_c0cd03
load_conditional_map_piece_c0ccdf:
    lda $A0
    bne load_conditional_map_piece_c0cd03
    lda $14
    sta $A0
    lda $15
    sta $A1
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $C6
    lda $A0
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $C4
    sep #$20
load_conditional_map_piece_c0cd03:
    rep #$10
    lda $00
    .a8
    and #$03
    beq load_conditional_map_piece_c0cd38
    .i16
    ldx #$0000
load_conditional_map_piece_c0cd0e:
    lda [$1D],Y
    sta a:$FF00,X
    iny
    inx
    tya
    clc
    adc $1D
    sta a:$FF00,X
    inx
    lda $1E
    .a8
    adc #$00
    sta a:$FF00,X
    inx
    lda $1F
    .a8
    adc #$00
    sta a:$FF00,X
    inx
load_conditional_map_piece_c0cd2d:
    lda [$1D],Y
    iny
    .a8
    cmp #$F8
    bcc load_conditional_map_piece_c0cd2d
    .a8
    cmp #$FF
    bne load_conditional_map_piece_c0cd0e
load_conditional_map_piece_c0cd38:
    rep #$20
    tya
    clc
    adc $1D
    sta $1D
    sep #$30
    bcc load_conditional_map_piece_c0cd46
    inc $1F
load_conditional_map_piece_c0cd46:
    jsr decode_map_piece_body
    sep #$30
    stz $26
load_conditional_map_piece_c0cd4d:
    ldx $26
    lda a:$FF20,X
    bne load_conditional_map_piece_c0cd55
    rts
load_conditional_map_piece_c0cd55:
    pha
    lda a:$FF22,X
    sta $12
    lda a:$FF23,X
    sta $13
    pla
    asl
    asl
    tax
    lda a:$FF00,X
    pha
    .a8
    and #$0F
    inc
    sta $14
    pla
    lsr
    lsr
    lsr
    lsr
    inc
    sta $15
    lda a:$FF01,X
    sta $1D
    lda a:$FF02,X
    sta $1E
    lda a:$FF03,X
    sta $1F
    jsr decode_map_piece_body
    sep #$30
    lda $26
    clc
    .a8
    adc #$04
    sta $26
    bra load_conditional_map_piece_c0cd4d
    rts
