; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-graphics-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e809b = $809B
routine_7e8fc7 = $8FC7
routine_7e90da = $90DA
routine_7eb0a1 = $B0A1
routine_7ebbab = $BBAB
routine_7ebbfe = $BBFE
routine_7ebc9a = $BC9A

.segment "CODE"
.org $9405
finish_warm_graphics_palette_and_workspace_constructor:
    jsr routine_7e809b
    stx $03
    .a16
    lda #$0001
    jsr routine_7e8fc7
    lda $03
    sta a:$000A,X
    .a16
    lda #$5200
    sta a:$0002,X
    .a16
    lda #$05C0
    sta a:$0005,X
    sep #$20
    .a8
    lda #$7E
    sta a:$0004,X
    jsr routine_7e90da
    .a8
    lda #$08
    jsr routine_7ebbab
    phx
    .a8
    lda #$7E
    xba
    .a8
    lda #$1E
    .i16
    ldy #$5160
    jsr routine_7ebc9a
    plx
    jsr routine_7ebbfe
    .i16
    ldx #$0020
    .a8
    lda #$00
    jsr routine_7eb0a1
    stx a:$007C
    .i16
    ldx #$0008
    .a8
    lda #$00
    jsr routine_7eb0a1
    stx a:$007E
    pla
    pla
    pla
    pla
    plp
    pld
    rts
