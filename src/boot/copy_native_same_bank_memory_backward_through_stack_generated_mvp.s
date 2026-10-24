; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-backward-memory-copy.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C4DC
copy_native_same_bank_memory_backward_through_stack_generated_mvp:
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
    bne copy_native_same_bank_memory_backward_through_stack_generated_mvp_c4f2
    jmp copy_native_same_bank_memory_backward_through_stack_generated_mvp_c57a
copy_native_same_bank_memory_backward_through_stack_generated_mvp_c4f2:
    .a16
    cmp #$0015
    bcc copy_native_same_bank_memory_backward_through_stack_generated_mvp_c545
    phb
    dec
    sta $05
    sep #$20
    .a8
    lda #$44
    sta $01
    lda $01,S
    sta $02
    lda $01,S
    sta $03
    .a8
    lda #$60
    sta $04
    clc
    rep #$20
    txa
    adc $05
    tax
    sep #$20
    clc
    rep #$20
    tya
    adc $05
    tay
    sep #$20
    inc $06
copy_native_same_bank_memory_backward_through_stack_generated_mvp_c521:
    php
    rep #$20
    .a16
    lda #$C536
    pha
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
    rts
    xba
    plp
    xba
    sta $05
    dec $06
    bne copy_native_same_bank_memory_backward_through_stack_generated_mvp_c521
    plb
    rep #$20
    bra copy_native_same_bank_memory_backward_through_stack_generated_mvp_c57a
copy_native_same_bank_memory_backward_through_stack_generated_mvp_c545:
    sta $05
    clc
    txa
    adc $05
    tax
    clc
    tya
    adc $05
    tay
    lda $05
    .a16
    bit #$0001
    beq copy_native_same_bank_memory_backward_through_stack_generated_mvp_c569
    dex
    dey
    sep #$20
    lda a:$0000,X
    sta a:$0000,Y
    rep #$20
    lda $05
    dec
    beq copy_native_same_bank_memory_backward_through_stack_generated_mvp_c57a
copy_native_same_bank_memory_backward_through_stack_generated_mvp_c569:
    lsr
    sta $05
copy_native_same_bank_memory_backward_through_stack_generated_mvp_c56c:
    dex
    dex
    dey
    dey
    lda a:$0000,X
    sta a:$0000,Y
    dec $05
    bne copy_native_same_bank_memory_backward_through_stack_generated_mvp_c56c
copy_native_same_bank_memory_backward_through_stack_generated_mvp_c57a:
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
