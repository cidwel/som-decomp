; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-resource-memory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C3BF
copy_native_same_bank_memory_through_stack_generated_mvn:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    .a16
    cmp #$0000
    bne copy_native_same_bank_memory_through_stack_generated_mvn_c3d5
    jmp copy_native_same_bank_memory_through_stack_generated_mvn_c445
copy_native_same_bank_memory_through_stack_generated_mvn_c3d5:
    .a16
    cmp #$0015
    bcc copy_native_same_bank_memory_through_stack_generated_mvn_c41e
    phb
    dec
    sta $05
    sep #$20
    .a8
    lda #$54
    sta $01
    lda $01,S
    sta $02
    lda $01,S
    sta $03
    .a8
    lda #$6B
    sta $04
    inc $06
copy_native_same_bank_memory_through_stack_generated_mvn_c3f2:
    php
    .a8
    lda #$7E
    pha
    rep #$20
    .a16
    lda #$C411
    pha
    sep #$20
    .a8
    lda #$00
    pha
    rep #$20
    tdc
    clc
    .a16
    adc #$0000
    pha
    sep #$20
    .a8
    lda #$00
    xba
    lda $05
    sei
    rtl
    plp
    sta $05
    dec $06
    bne copy_native_same_bank_memory_through_stack_generated_mvn_c3f2
    plb
    rep #$20
    bra copy_native_same_bank_memory_through_stack_generated_mvn_c445
copy_native_same_bank_memory_through_stack_generated_mvn_c41e:
    .a16
    bit #$0001
    beq copy_native_same_bank_memory_through_stack_generated_mvn_c434
    pha
    sep #$20
    lda a:$0000,X
    sta a:$0000,Y
    rep #$20
    inx
    iny
    pla
    dec
    beq copy_native_same_bank_memory_through_stack_generated_mvn_c445
copy_native_same_bank_memory_through_stack_generated_mvn_c434:
    lsr
    sta $05
copy_native_same_bank_memory_through_stack_generated_mvn_c437:
    lda a:$0000,X
    sta a:$0000,Y
    inx
    inx
    iny
    iny
    dec $05
    bne copy_native_same_bank_memory_through_stack_generated_mvn_c437
copy_native_same_bank_memory_through_stack_generated_mvn_c445:
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
