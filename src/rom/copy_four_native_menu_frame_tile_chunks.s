; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $205A
copy_four_native_menu_frame_tile_chunks:
    .i16
    ldx #$0000
    .a8
    lda #$04
    sta a:$A175
copy_four_native_menu_frame_tile_chunks_c02062:
    .a8
    lda #$08
copy_four_native_menu_frame_tile_chunks_c02064:
    xba
    lda f:$C777E5,X
    sta a:$9000,Y
    inx
    iny
    xba
    dec
    bne copy_four_native_menu_frame_tile_chunks_c02064
    rep #$20
    tya
    clc
    .a16
    adc #$0038
    tay
    sep #$20
    dec a:$A175
    bne copy_four_native_menu_frame_tile_chunks_c02062
    rts
