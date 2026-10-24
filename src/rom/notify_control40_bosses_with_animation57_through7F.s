; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-party-services.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0396
notify_control40_bosses_with_animation57_through7F:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    .i16
    ldy #$0003
notify_control40_bosses_with_animation57_through7F_c203a8:
    tya
    xba
    asl
    tax
    sep #$20
    lda a:$E060,X
    .a8
    cmp #$40
    bne notify_control40_bosses_with_animation57_through7F_c203c5
    lda a:$E180,X
    .a8
    cmp #$57
    bcc notify_control40_bosses_with_animation57_through7F_c203c5
    .a8
    cmp #$80
    bcs notify_control40_bosses_with_animation57_through7F_c203c5
    .a8
    lda #$01
    sta a:$E061,X
notify_control40_bosses_with_animation57_through7F_c203c5:
    rep #$30
    iny
    .i16
    cpy #$0006
    bcc notify_control40_bosses_with_animation57_through7F_c203a8
    plb
    pld
    plp
    rtl
