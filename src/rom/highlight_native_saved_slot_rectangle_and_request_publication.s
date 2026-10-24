; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

native_menu_change_sound_long_wrapper = $C02AF2

.segment "CODE"
.org $57DC
highlight_native_saved_slot_rectangle_and_request_publication:
    .a8
    lda #$18
    sta a:$A1CB
    rep #$20
    lda a:$A211
    .a16
    and #$00FF
    asl
    asl
    tax
    lda a:$A1E0,X
    pha
    lda a:$A1E2,X
    sta a:$A16B
    sep #$20
    lda a:$A16B
    inc
    inc
    sta a:$A163
    plx
highlight_native_saved_slot_rectangle_and_request_publication_c75801:
    lda a:$A16C
    inc
    inc
    sta a:$A164
    phx
highlight_native_saved_slot_rectangle_and_request_publication_c7580a:
    lda a:$9001,X
    .a8
    and #$E3
    ora a:$A1CB
    sta a:$9001,X
    inx
    inx
    dec a:$A164
    bne highlight_native_saved_slot_rectangle_and_request_publication_c7580a
    rep #$20
    pla
    clc
    .a16
    adc #$0040
    tax
    sep #$20
    dec a:$A163
    bne highlight_native_saved_slot_rectangle_and_request_publication_c75801
    lda a:$A202
    .a8
    cmp #$06
    beq highlight_native_saved_slot_rectangle_and_request_publication_c75836
    jsl f:native_menu_change_sound_long_wrapper
highlight_native_saved_slot_rectangle_and_request_publication_c75836:
    .a8
    lda #$02
    tsb a:$A20A
    rtl
