; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-spare-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A39F
clone_selected_actor_fields_into_spare_record:
    rep #$20
    phx
    phy
    txa
    .a16
    ora #$E000
    tax
    tya
    .a16
    ora #$E000
    tay
    .a16
    lda #$006B
    mvn #$7E, #$7E
    inx
    inx
    inx
    inx
    iny
    iny
    iny
    iny
    .a16
    lda #$0015
    mvn #$7E, #$7E
    tya
    clc
    .a16
    adc #$0006
    tay
    txa
    clc
    .a16
    adc #$0006
    tax
    .a16
    lda #$0173
    mvn #$7E, #$7E
    ply
    plx
    sep #$20
    lda a:$E08B,X
    .a8
    and #$F0
    sta $00
    lda a:$E08B,Y
    .a8
    and #$0F
    ora $00
    sta a:$E08B,Y
    .a8
    lda #$FF
    sta a:$E030,Y
    tyx
    stz a:$E104,X
    stz a:$E100,X
    stz a:$E083,X
    stz a:$E084,X
    stz a:$E01C,X
    stz a:$E00A,X
    stz a:$E064,X
    stz a:$E062,X
    rtl
