; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

append_one_merged_actor_effect_piece = $90B7

.segment "CODE"
.org $9017
prepare_merged_actor_effect_sprites:
    sep #$20
    ldx $14
    lda a:$E110,X
    ora a:$E120,X
    ora a:$E130,X
    .a8
    cmp #$03
    beq prepare_merged_actor_effect_sprites_c1902a
    clc
    rtl
prepare_merged_actor_effect_sprites_c1902a:
    rep #$20
    txa
    lsr
    tay
    lda a:$C06C,Y
    sta a:$C060,Y
    sta a:$C064,Y
    sta a:$C068,Y
    .a16
    lda #$0000
    sep #$20
    lda a:$E010,X
    rep #$20
    beq prepare_merged_actor_effect_sprites_c1905e
    bmi prepare_merged_actor_effect_sprites_c19051
    dec
    beq prepare_merged_actor_effect_sprites_c19059
    .a16
    lda #$0018
    bra prepare_merged_actor_effect_sprites_c19054
prepare_merged_actor_effect_sprites_c19051:
    .a16
    lda #$FFE8
prepare_merged_actor_effect_sprites_c19054:
    .i16
    ldy #$0000
    bra prepare_merged_actor_effect_sprites_c19064
prepare_merged_actor_effect_sprites_c19059:
    .i16
    ldy #$0018
    bra prepare_merged_actor_effect_sprites_c19061
prepare_merged_actor_effect_sprites_c1905e:
    .i16
    ldy #$FFE8
prepare_merged_actor_effect_sprites_c19061:
    .a16
    lda #$0000
prepare_merged_actor_effect_sprites_c19064:
    clc
    adc a:$E020,X
    sta $04
    sty $06
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    sec
    adc $06
    clc
    adc a:$E022,X
    sta $06
    rep #$20
    stz $02
    lda $14
    lsr
    .a16
    ora #$0060
    tax
    ldy $14
    jsr append_one_merged_actor_effect_piece
    rep #$20
    lda $14
    .a16
    ora #$0010
    tay
    jsr append_one_merged_actor_effect_piece
    rep #$20
    lda $14
    .a16
    ora #$0020
    tay
    jsr append_one_merged_actor_effect_piece
    rep #$20
    lda $14
    lsr
    .a16
    ora #$C060
    tax
    lda $02
    .a16
    cmp #$0001
    rtl
