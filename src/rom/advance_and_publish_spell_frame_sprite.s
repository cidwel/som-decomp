; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

publish_spell_frame_projection_long = $C12E84

.segment "CODE"
.org $F683
advance_and_publish_spell_frame_sprite:
    phd
    php
    rep #$20
    sep #$20
    lda a:$0003,Y
    clc
    adc a:$0005,X
    sta a:$0005,X
    rep #$20
    lda a:$0004,Y
    adc a:$0006,X
    sta a:$0006,X
    sep #$20
    lda a:$0000,Y
    clc
    adc a:$0002,X
    sta a:$0002,X
    rep #$20
    lda a:$0001,Y
    adc a:$0003,X
    sta a:$0003,X
    ldy a:$0000,X
    sta a:$0002,Y
    lda a:$0006,X
    sta a:$0004,Y
    tyx
    jsl f:publish_spell_frame_projection_long
    plp
    pld
    rts
