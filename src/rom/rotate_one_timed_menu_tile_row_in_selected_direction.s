; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-menu-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BC30
rotate_one_timed_menu_tile_row_in_selected_direction:
    .a8
    cmp #$01
    lda a:$D20C,X
    bne rotate_one_timed_menu_tile_row_in_selected_direction_c2bc38
    rts
rotate_one_timed_menu_tile_row_in_selected_direction_c2bc38:
    pha
    rep #$20
    lda a:$D20A,X
    sta $02
    lda a:$D204,X
    plx
    rep #$10
    bcs rotate_one_timed_menu_tile_row_in_selected_direction_c2bc63
    sep #$20
    ora $03
    rep #$20
    tay
    lda a:$0600,Y
    pha
rotate_one_timed_menu_tile_row_in_selected_direction_c2bc53:
    lda a:$05FE,Y
    sta a:$0600,Y
    dey
    dey
    dex
    bne rotate_one_timed_menu_tile_row_in_selected_direction_c2bc53
    pla
    sta a:$0600,Y
    rts
rotate_one_timed_menu_tile_row_in_selected_direction_c2bc63:
    sep #$20
    ora $02
    rep #$20
    tay
    lda a:$0600,Y
    pha
rotate_one_timed_menu_tile_row_in_selected_direction_c2bc6e:
    lda a:$0602,Y
    sta a:$0600,Y
    iny
    iny
    dex
    bne rotate_one_timed_menu_tile_row_in_selected_direction_c2bc6e
    pla
    sta a:$0600,Y
    rts
