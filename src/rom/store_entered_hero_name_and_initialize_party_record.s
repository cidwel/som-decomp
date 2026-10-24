; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-hero-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_hero_record_public_jump = $C00039

.segment "CODE"
.org $507F
store_entered_hero_name_and_initialize_party_record:
    lda a:$A1CC
    pha
    rep #$20
    lda a:$A22B
    asl
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tax
    phx
    sep #$20
    .a8
    lda #$0C
store_entered_hero_name_and_initialize_party_record_c75098:
    stz a:$CC00,X
    inx
    dec
    bne store_entered_hero_name_and_initialize_party_record_c75098
    stz a:$A1CD
    ply
    rep #$20
    .i16
    ldx #$00D2
store_entered_hero_name_and_initialize_party_record_c750a8:
    lda a:$9000,X
    phx
    sec
    .a16
    sbc #$2058
    lsr
    tax
    sep #$20
    lda f:$C774B2,X
    sta a:$CC00,Y
    rep #$20
    iny
    plx
    inx
    inx
    dec a:$A1CC
    bne store_entered_hero_name_and_initialize_party_record_c750a8
    sep #$20
    pla
    sta a:$A1CC
    rep #$20
    lda a:$A22B
    .a16
    and #$00FF
    xba
    asl
    tax
    sep #$20
    php
    jsl f:initialize_hero_record_public_jump
    plp
    rtl
