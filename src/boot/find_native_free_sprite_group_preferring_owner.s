; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sprite-record-search.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B671
find_native_free_sprite_group_preferring_owner:
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
    ldx a:$02CA
    beq find_native_free_sprite_group_preferring_owner_b6cc
    sta $01
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    .i16
    ldy #$0020
find_native_free_sprite_group_preferring_owner_b691:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    bne find_native_free_sprite_group_preferring_owner_b6a7
    lda a:$000B,X
    cmp $01
    beq find_native_free_sprite_group_preferring_owner_b6cc
find_native_free_sprite_group_preferring_owner_b6a7:
    dey
    bne find_native_free_sprite_group_preferring_owner_b691
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    .i16
    ldy #$0020
find_native_free_sprite_group_preferring_owner_b6b7:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    beq find_native_free_sprite_group_preferring_owner_b6cc
    dey
    bne find_native_free_sprite_group_preferring_owner_b6b7
    .i16
    ldx #$0000
find_native_free_sprite_group_preferring_owner_b6cc:
    pla
    plp
    pld
    rts
