; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-resource-memory.md.
.setcpu "65816"
.smart
.a8
.i16

copy_native_same_bank_memory_through_stack_generated_mvn = $C3BF

.segment "CODE"
.org $C37D
fill_native_boot_memory_using_words_or_forward_copy:
    phd
    php
    rep #$30
    sep #$20
    .i16
    cpy #$0000
    beq fill_native_boot_memory_using_words_or_forward_copy_c3bc
    sta a:$0000,X
    .i16
    cpy #$0081
    bcc fill_native_boot_memory_using_words_or_forward_copy_c39f
    rep #$20
    tya
    txy
    iny
    dec
    sep #$20
    beq fill_native_boot_memory_using_words_or_forward_copy_c3bc
    jsr copy_native_same_bank_memory_through_stack_generated_mvn
    bra fill_native_boot_memory_using_words_or_forward_copy_c3bc
fill_native_boot_memory_using_words_or_forward_copy_c39f:
    pha
    tya
    .a8
    and #$01
    beq fill_native_boot_memory_using_words_or_forward_copy_c3ab
    pla
    inx
    dey
    beq fill_native_boot_memory_using_words_or_forward_copy_c3bc
    pha
fill_native_boot_memory_using_words_or_forward_copy_c3ab:
    lda $01,S
    xba
    pla
    rep #$20
fill_native_boot_memory_using_words_or_forward_copy_c3b1:
    sta a:$0000,X
    inx
    inx
    dey
    dey
    bne fill_native_boot_memory_using_words_or_forward_copy_c3b1
    sep #$20
fill_native_boot_memory_using_words_or_forward_copy_c3bc:
    plp
    pld
    rts
