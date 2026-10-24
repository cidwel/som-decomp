; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-title-workers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8820 = $8820
routine_7e8ab5 = $8AB5
routine_7e8b00 = $8B00
routine_7e8b5d = $8B5D
routine_7e8dac = $8DAC
routine_7eacd0 = $ACD0
routine_7eb1a9 = $B1A9
routine_7eb1dd = $B1DD
routine_7eb258 = $B258
routine_7eb2fb = $B2FB
routine_7ec870 = $C870

.segment "CODE"
.org $8DCD
run_native_title_credit_worker_and_complete_buffer_notice:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0009
    tcd
    tcs
    sep #$20
    jsr routine_7eacd0
    sta $01
    jsr routine_7eb1a9
    .a8
    lda #$01
    sta a:$0003,X
    lda $01
    jsr routine_7eb258
    jsr routine_7eb2fb
    rep #$20
    lda a:$0004,X
    sta $02
    clc
    .a16
    adc #$0440
    sta $04
    jsr routine_7eb1dd
    .i16
    ldx #$003C
    jsr routine_7e8b00
    jsr routine_7e8ab5
    sep #$20
    .i16
    ldx #$01BE
    stx $08
run_native_title_credit_worker_and_complete_buffer_notice_8e0f:
    ldy $04
    jsr routine_7e8820
    .i16
    cpx #$0000
    beq run_native_title_credit_worker_and_complete_buffer_notice_8e66
    stx $08
    ldx $02
    jsr routine_7ec870
    .a8
    lda #$1F
    sta $06
run_native_title_credit_worker_and_complete_buffer_notice_8e24:
    .i16
    ldx #$0001
    jsr routine_7e8b00
    .a8
    lda #$20
    sec
    sbc $06
    asl
    rep #$20
    .a16
    and #$00FF
    tax
    jsr routine_7e8b5d
    sep #$20
    dec $06
    bne run_native_title_credit_worker_and_complete_buffer_notice_8e24
    .i16
    ldx #$00F0
    jsr routine_7e8b00
    .a8
    lda #$1F
    sta $06
run_native_title_credit_worker_and_complete_buffer_notice_8e49:
    .i16
    ldx #$0001
    jsr routine_7e8b00
    lda $06
    dec
    asl
    rep #$20
    .a16
    and #$00FF
    tax
    jsr routine_7e8b5d
    sep #$20
    dec $06
    bne run_native_title_credit_worker_and_complete_buffer_notice_8e49
    ldx $08
    bne run_native_title_credit_worker_and_complete_buffer_notice_8e0f
run_native_title_credit_worker_and_complete_buffer_notice_8e66:
    .i16
    ldx #$019E
    ldy $04
    jsr routine_7e8820
    ldx $02
    jsr routine_7ec870
    .i16
    ldx #$0001
    jsr routine_7e8b00
    jsr routine_7e8dac
    jsr routine_7eb1a9
    .a8
    lda #$02
    sta a:$0003,X
    lda $01
    jsr routine_7eb258
    rep #$20
    tsc
    clc
    .a16
    adc #$0009
    tcs
    plp
    pld
    rtl
