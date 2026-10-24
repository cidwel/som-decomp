; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-dirty-sprite-sort.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0a1 = $B0A1
routine_7eb0d6 = $B0D6
routine_7eb840 = $B840

.segment "CODE"
.org $B8CF
sort_native_dirty_sprite_records_and_enter_literal_permutation:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    lda a:$02D0
    beq sort_native_dirty_sprite_records_and_enter_literal_permutation_b93d
    stz a:$02D0
    .i16
    ldx #$0100
    .a8
    lda #$00
    jsr routine_7eb0a1
    .i16
    cpx #$0000
    beq sort_native_dirty_sprite_records_and_enter_literal_permutation_b93d
    stx $03
    rep #$20
    .a16
    lda #$0020
    sta $01
    ldx a:$02C8
sort_native_dirty_sprite_records_and_enter_literal_permutation_b902:
    lda a:$000A,X
    lsr
    lsr
    clc
    adc $03
    tay
    txa
    sta a:$0000,Y
    clc
    .a16
    adc #$0010
    tax
    dec $01
    bne sort_native_dirty_sprite_records_and_enter_literal_permutation_b902
    sep #$20
    ldx $03
    dex
    dex
    .a8
    lda #$80
    sta $01
sort_native_dirty_sprite_records_and_enter_literal_permutation_b922:
    inx
    inx
    ldy a:$0000,X
    beq sort_native_dirty_sprite_records_and_enter_literal_permutation_b922
    lda $01
    sec
    .a8
    sbc #$04
    sta a:$0009,Y
    sta $01
    bne sort_native_dirty_sprite_records_and_enter_literal_permutation_b922
    ldx $03
    jsr routine_7eb0d6
    jsr routine_7eb840
sort_native_dirty_sprite_records_and_enter_literal_permutation_b93d:
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
