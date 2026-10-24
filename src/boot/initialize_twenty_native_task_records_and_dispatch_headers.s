; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
copy_native_same_bank_memory_through_stack_generated_mvn = $C3BF

.segment "CODE"
.org $A826
initialize_twenty_native_task_records_and_dispatch_headers:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .i16
    ldx #$0140
    .a16
    lda #$0000
    jsr allocate_and_fill_bytes
    stx a:$009C
    stx a:$00A6
    .i16
    ldy #$0013
initialize_twenty_native_task_records_and_dispatch_headers_a848:
    txa
    clc
    .a16
    adc #$0010
    sta a:$0000,X
    tax
    dey
    bne initialize_twenty_native_task_records_and_dispatch_headers_a848
    stz a:$00A0
    stz a:$00A2
    stz a:$00AA
    .i16
    ldx #$00AA
    .i16
    ldy #$00AB
    .a16
    lda #$0013
    jsr copy_native_same_bank_memory_through_stack_generated_mvn
    stz a:$009E
    stz a:$00A0
    stz a:$00A2
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
