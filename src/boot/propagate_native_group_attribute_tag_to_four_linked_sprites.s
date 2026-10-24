; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-group-attribute-tag.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B7CB
propagate_native_group_attribute_tag_to_four_linked_sprites:
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
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    cmp a:$000B,X
    beq propagate_native_group_attribute_tag_to_four_linked_sprites_b7ff
    sta a:$000B,X
    xba
    .a8
    lda #$04
    sta $01
    xba
    lsr
    lsr
propagate_native_group_attribute_tag_to_four_linked_sprites_b7ee:
    ldy a:$0000,X
    sta a:$000B,Y
    inx
    inx
    dec $01
    bne propagate_native_group_attribute_tag_to_four_linked_sprites_b7ee
    .a8
    lda #$01
    sta a:$02D0
propagate_native_group_attribute_tag_to_four_linked_sprites_b7ff:
    plb
    pla
    plp
    pld
    rts
