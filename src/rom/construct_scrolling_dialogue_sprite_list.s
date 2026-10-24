; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

activate_native_entity_sprite_long = $C12E80
allocate_and_fill_spell_entity_bytes_long = $C12E78

.segment "CODE"
.org $F4F1
construct_scrolling_dialogue_sprite_list:
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
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    .i16
    ldx #$0112
    .a16
    lda #$0000
    jsl f:allocate_and_fill_spell_entity_bytes_long
    stx $03
    .a16
    lda #$FFFF
    sta a:$010C,X
    .a16
    lda #$0001
    sta a:$0110,X
    stx $05
    .a16
    lda #$0028
    sta $01
construct_scrolling_dialogue_sprite_list_d3f529:
    .a16
    lda #$000F
    jsl f:activate_native_entity_sprite_long
    dec $01
    bne construct_scrolling_dialogue_sprite_list_d3f529
    .a16
    lda #$0018
    sta $01
construct_scrolling_dialogue_sprite_list_d3f539:
    .a16
    lda #$000F
    jsl f:activate_native_entity_sprite_long
    .a16
    lda #$0000
    sta a:$0000,X
    txa
    ldx $05
    sta a:$0000,X
    clc
    txa
    .a16
    adc #$000A
    tax
    stx $05
    dec $01
    bne construct_scrolling_dialogue_sprite_list_d3f539
    ldx $03
    plb
    sta $05,S
    tsc
    clc
    .a16
    adc #$0004
    tcs
    pla
    plp
    pld
    rtl
