; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-resource-ppu.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
routine_7eb081 = $B081

.segment "CODE"
.org $BF6E
initialize_native_boot_ppu_shadow_and_sixty_three_record_pool:
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
    .a16
    lda #$0000
    .i16
    ldx #$0060
    jsr allocate_and_fill_bytes
    stx a:$02E2
    sep #$20
    .a8
    lda #$0F
    sta a:$0000,X
    .a8
    lda #$30
    sta a:$0030,X
    .a8
    lda #$E0
    sta a:$0032,X
    .i16
    ldx #$0100
    jsr routine_7eb081
    rep #$20
    stx a:$02D6
    txa
    clc
    .a16
    adc #$0004
    sta a:$02D8
    tax
    .i16
    ldy #$003E
initialize_native_boot_ppu_shadow_and_sixty_three_record_pool_bfb2:
    clc
    .a16
    adc #$0004
    sta a:$0000,X
    tax
    dey
    bne initialize_native_boot_ppu_shadow_and_sixty_three_record_pool_bfb2
    stz a:$0000,X
    stz a:$02DE
    .a16
    lda #$02DE
    sta a:$02E0
    stz a:$02DA
    .a16
    lda #$02DA
    sta a:$02DC
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
