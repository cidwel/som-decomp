; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-menu-records.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_one_timed_menu_tile_row_in_selected_direction = $BC30

.segment "CODE"
.org $BB0F
advance_one_timed_menu_tile_record_and_publish_native_tiles:
    .a8
    cmp #$04
    bcs advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb3d
    .a8
    cmp #$03
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb1b
    .a8
    lda #$04
    bra advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb3d
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb1b:
    .a8
    cmp #$02
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb3a
    lda a:$D201,X
    tay
    lda a:$D206,X
    inc
    cmp a:$D20C,X
    bcc advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb36
    lda a:$D201,X
    .a8
    eor #$01
    sta a:$D201,X
    .a8
    lda #$00
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb36:
    sta a:$D206,X
    tya
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb3a:
    jmp rotate_one_timed_menu_tile_row_in_selected_direction
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb3d:
    .a8
    cmp #$05
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb6f
    inc a:$D206,X
    rep #$30
    lda a:$D204,X
    .a16
    ora #$001E
    tay
    lda a:$D206,X
    asl
    .a16
    and #$001E
    .a16
    cmp #$001E
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb60
    lda a:$DE00,Y
    sta a:$0600,Y
    rts
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb60:
    clc
    adc a:$D208,X
    phx
    tax
    lda f:$C80000,X
    sta a:$0600,Y
    plx
    rts
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb6f:
    .a8
    cmp #$04
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bbcb
    lda a:$D201,X
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb8d
    lda a:$D206,X
    tay
    inc
    .a8
    cmp #$0F
    bcc advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb9e
    lda a:$D201,X
    .a8
    eor #$01
    sta a:$D201,X
    .a8
    lda #$0F
    bra advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb9e
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb8d:
    lda a:$D206,X
    tay
    dec
    bpl advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb9e
    lda a:$D201,X
    .a8
    eor #$01
    sta a:$D201,X
    .a8
    lda #$00
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bb9e:
    sta a:$D206,X
    tya
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    rep #$30
    lda a:$D204,X
    inc
    inc
    .a16
    ora #$0600
    tay
    lda a:$D208,X
    clc
    adc f:$004216
    phx
    tax
    .a16
    lda #$001D
    mvn #$7E, #$7E
    plx
    sep #$30
    rts
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bbcb:
    .a8
    cmp #$07
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc07
    lda a:$D206,X
    inc
    .a8
    cmp #$10
    bcc advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bbd9
    .a8
    lda #$00
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bbd9:
    sta a:$D206,X
    .a8
    cmp #$0F
    beq advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc18
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bbe0:
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    rep #$30
    lda a:$D204,X
    inc
    inc
    .a16
    ora #$0600
    tay
    lda a:$D208,X
    clc
    adc f:$004216
    phx
    tax
    .a16
    lda #$001D
    mvn #$C8, #$7E
    plx
    rts
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc07:
    lda a:$D206,X
    inc
    .a8
    cmp #$08
    bcc advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc11
    .a8
    lda #$00
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc11:
    sta a:$D206,X
    .a8
    cmp #$07
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bbe0
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc18:
    lda a:$D204,X
    tay
    phx
    .i8
    ldx #$0F
    rep #$20
advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc21:
    lda a:$DE02,Y
    sta a:$0602,Y
    iny
    iny
    dex
    bne advance_one_timed_menu_tile_record_and_publish_native_tiles_c2bc21
    sep #$20
    plx
    rts
