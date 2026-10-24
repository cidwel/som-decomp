; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-row.md.
.setcpu "65816"
.smart
.a8
.i16

project_native_menu_ring_angle_and_radius_to_centered_coordinates = $D9FC00
request_native_menu_audio_29 = $D0CF10
test_native_menu_ring_row_coordinates_for_visibility = $6E8D

.segment "CODE"
.org $6D74
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam:
    sep #$20
    lda a:$1812
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d81
    .a8
    cmp #$03
    bcs update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d93
    bra update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d88
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d81:
    lda a:$1806
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06ddf
    bmi update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d93
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d88:
    rep #$20
    lda $08,X
    tay
    sec
    sbc a:$1824
    bra update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d9c
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d93:
    rep #$20
    lda $08,X
    tay
    clc
    adc a:$1824
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06d9c:
    pha
    .a16
    and #$03FF
    sta $08,X
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06db2
    pla
    .a16
    and #$FC00
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06ddf
    tya
    .a16
    cmp #$0000
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06ddf
    bra update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06db8
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06db2:
    pla
    sep #$20
    stz a:$1807
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06db8:
    sep #$20
    lda a:$1806
    clc
    adc a:$180A
    stz a:$180A
    cmp a:$180B
    bcc update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06dcf
    bpl update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06dd2
    lda a:$180B
    dec
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06dcf:
    sta a:$180A
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06dd2:
    sep #$20
    lda a:$1812
    bne update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06ddf
    rep #$20
    jsl f:request_native_menu_audio_29
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06ddf:
    rep #$30
    phx
    lda a:$181A
    sta a:$186A
    lda $08,X
    pha
    lda a:$1847
    .a16
    and #$00FF
    dec
    bne update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06dfc
    lda $01,S
    clc
    .a16
    adc #$0200
    sta $01,S
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06dfc:
    pla
    sta a:$1868
    jsl f:project_native_menu_ring_angle_and_radius_to_centered_coordinates
    plx
    sta $04,X
    sty $02,X
    jsr test_native_menu_ring_row_coordinates_for_visibility
    bcc update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e15
    .a16
    lda #$00E8
    sta $04,X
    bra update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e18
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e15:
    stz a:$180C
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e18:
    ldy a:$1832
    sep #$20
    lda $00,X
    bpl update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e36
    inc a:$1822
    lda a:$1822
    .a8
    cmp #$05
    bcc update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e36
    .a8
    cmp #$09
    bcc update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e32
    stz a:$1822
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e32:
    .a8
    lda #$E8
    sta $04,X
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e36:
    lda $04,X
    xba
    lda $02,X
    rep #$20
    sta a:$0000,Y
    iny
    iny
    lda a:$1822
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e53
    lda $00,X
    bpl update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e53
    lda $06,X
    clc
    adc a:$1822
    bra update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e55
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e53:
    lda $06,X
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e55:
    sta a:$0000,Y
    iny
    iny
    sty a:$1832
    lda $0A,X
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e8a
    tay
    sep #$20
    lda a:$1847
    dec
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e8a
    lda $04,X
    .a8
    cmp #$E8
    beq update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e83
    xba
    lda $02,X
    rep #$20
    clc
    .a16
    adc #$0505
    sta a:$0000,Y
    lda $02,X
    .a16
    cmp #$00FB
    bcc update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e8a
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e83:
    sep #$20
    .a8
    lda #$E8
    sta a:$0001,Y
update_native_menu_ring_row_angle_project_coordinates_and_publish_oam_c06e8a:
    rep #$30
    rts
