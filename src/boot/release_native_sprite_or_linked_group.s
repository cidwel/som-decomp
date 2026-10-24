; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sprite-release-modes.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb75f = $B75F

.segment "CODE"
.org $B786
release_native_sprite_or_linked_group:
    phd
    php
    rep #$30
    phb
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    lda a:$02CE
    beq release_native_sprite_or_linked_group_b79e
    jsr routine_7eb75f
    bra release_native_sprite_or_linked_group_b7b4
release_native_sprite_or_linked_group_b79e:
    stz a:$0008,X
    txy
    .a8
    lda #$04
    sta $01
release_native_sprite_or_linked_group_b7a6:
    phy
    ldx a:$0000,Y
    jsr routine_7eb75f
    ply
    iny
    iny
    dec $01
    bne release_native_sprite_or_linked_group_b7a6
release_native_sprite_or_linked_group_b7b4:
    plb
    pla
    plp
    pld
    rts
