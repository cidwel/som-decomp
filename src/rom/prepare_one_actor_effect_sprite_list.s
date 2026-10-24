; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_actor_effect_direction_piece = $918A

.segment "CODE"
.org $9106
prepare_one_actor_effect_sprite_list:
    sep #$20
    lda a:$E110,Y
    beq prepare_one_actor_effect_sprite_list_c19116
    .a8
    cmp #$04
    bcs prepare_one_actor_effect_sprite_list_c19118
    lda a:$E114,Y
    beq prepare_one_actor_effect_sprite_list_c19118
prepare_one_actor_effect_sprite_list_c19116:
    clc
    rtl
prepare_one_actor_effect_sprite_list_c19118:
    rep #$20
    ldx $14
    lda a:$E084,X
    .a16
    and #$000F
    sta $02
    lda a:$E118,Y
    clc
    adc a:$E020,X
    sta $04
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    sec
    adc a:$E11A,Y
    adc a:$E022,X
    sta $06
    lda $14
    lsr
    .a16
    ora #$C000
    tax
    sep #$20
    lda a:$E110,Y
    .a8
    cmp #$01
    bne prepare_one_actor_effect_sprite_list_c1915b
    lda $02
    beq prepare_one_actor_effect_sprite_list_c19159
    sec
    rtl
prepare_one_actor_effect_sprite_list_c19159:
    clc
    rtl
prepare_one_actor_effect_sprite_list_c1915b:
    .a8
    cmp #$04
    bcs prepare_one_actor_effect_sprite_list_c1916b
    .a8
    lda #$03
    sta $02
    lda a:$E112,Y
    jsr select_actor_effect_direction_piece
    sec
    rtl
prepare_one_actor_effect_sprite_list_c1916b:
    bne prepare_one_actor_effect_sprite_list_c19188
    rep #$20
    lda $14
    lsr
    ora a:$E11C,Y
    .a16
    ora #$C000
    tax
    sep #$20
    lda a:$E113,Y
    lsr
    lsr
    sta $02
    beq prepare_one_actor_effect_sprite_list_c19186
    sec
    rtl
prepare_one_actor_effect_sprite_list_c19186:
    clc
    rtl
prepare_one_actor_effect_sprite_list_c19188:
    clc
    rtl
