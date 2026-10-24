; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sprite-record-search.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B612
find_native_free_sprite_record_preferring_owner:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    ldx a:$02C8
    beq find_native_free_sprite_record_preferring_owner_b66d
    sta $01
    clc
    rep #$20
    txa
    .a16
    adc #$0800
    tax
    sep #$20
    .i16
    ldy #$0080
find_native_free_sprite_record_preferring_owner_b632:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    bne find_native_free_sprite_record_preferring_owner_b648
    lda a:$000B,X
    cmp $01
    beq find_native_free_sprite_record_preferring_owner_b66d
find_native_free_sprite_record_preferring_owner_b648:
    dey
    bne find_native_free_sprite_record_preferring_owner_b632
    clc
    rep #$20
    txa
    .a16
    adc #$0800
    tax
    sep #$20
    .i16
    ldy #$0080
find_native_free_sprite_record_preferring_owner_b658:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    beq find_native_free_sprite_record_preferring_owner_b66d
    dey
    bne find_native_free_sprite_record_preferring_owner_b658
    .i16
    ldx #$0000
find_native_free_sprite_record_preferring_owner_b66d:
    pla
    plp
    pld
    rts
