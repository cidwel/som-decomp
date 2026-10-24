; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $58A8
unpack_three_saved_actor_name_prefixes:
    .i16
    ldy #$E000
    .a8
    lda #$03
    sta a:$A175
unpack_three_saved_actor_name_prefixes_c758b0:
    .a8
    lda #$06
    phy
unpack_three_saved_actor_name_prefixes_c758b3:
    xba
    lda f:$306000,X
    sta a:$0000,Y
    inx
    iny
    xba
    dec
    bne unpack_three_saved_actor_name_prefixes_c758b3
    rep #$20
    pla
    clc
    .a16
    adc #$0200
    tay
    sep #$20
    dec a:$A175
    bne unpack_three_saved_actor_name_prefixes_c758b0
    rts
