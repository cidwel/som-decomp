; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-title-workers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8820 = $8820
routine_7e88e7 = $88E7
routine_7e8ba5 = $8BA5
routine_7e8ca6 = $8CA6
routine_7eacd0 = $ACD0
routine_7eb1a9 = $B1A9
routine_7eb1dd = $B1DD
routine_7eb258 = $B258
routine_7eb2fb = $B2FB
routine_7ec3bf = $C3BF
routine_7ec870 = $C870

.segment "CODE"
.org $8D1A
run_native_title_normal_rows_and_complete_buffer_notice:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    sep #$20
    stz a:$0063
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
    jsr routine_7eb1dd
    jsr routine_7e88e7
    .i16
    ldx #$0000
    stx $04
run_native_title_normal_rows_and_complete_buffer_notice_8d51:
    lda $02
    clc
    .a16
    adc #$0480
    tay
    lda $02
    clc
    .a16
    adc #$04C0
    tax
    .a16
    lda #$0200
    jsr routine_7ec3bf
    ldx $02
    jsr routine_7ec870
    lda $02
    clc
    .a16
    adc #$0680
    tay
    ldx $04
    jsr routine_7e8820
    stx $04
    ldx $02
    jsr routine_7e8ba5
    lda $04
    bne run_native_title_normal_rows_and_complete_buffer_notice_8d51
    ldx $02
    jsr routine_7ec870
    jsr routine_7e8ca6
    jsr routine_7eb1a9
    .a16
    lda #$0002
    sta a:$0003,X
    lda $01
    jsr routine_7eb258
    tsc
    clc
    .a16
    adc #$0005
    tcs
    plp
    pld
    rtl
