; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_interior_sequential_tiles = $2533
skip_native_menu_interior_tile_columns = $2523

.segment "CODE"
.org $24E3
expand_native_menu_frame_vertical_pairs:
expand_native_menu_frame_vertical_pairs_c024e3:
    phx
    rep #$20
    .a16
    lda #$2022
    sta a:$9000,X
    sta a:$9040,X
    inx
    inx
    lda a:$A20A
    .a16
    and #$0008
    bne expand_native_menu_frame_vertical_pairs_c024fe
    jsr expand_native_menu_interior_sequential_tiles
    bra expand_native_menu_frame_vertical_pairs_c02501
expand_native_menu_frame_vertical_pairs_c024fe:
    jsr skip_native_menu_interior_tile_columns
expand_native_menu_frame_vertical_pairs_c02501:
    lda a:$A16C
    sta a:$A164
    rep #$20
    .a16
    lda #$6022
    sta a:$9000,X
    sta a:$9040,X
    pla
    clc
    .a16
    adc #$0080
    tax
    sep #$20
    dec a:$A163
    dec a:$A163
    bne expand_native_menu_frame_vertical_pairs_c024e3
    rts
