; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $462B
pack_mode_seven_scene_objects_into_complete_oam_buffer:
    rep #$20
    .i16
    ldx #$15E0
    .i16
    ldy #$0080
    .a16
    lda #$E000
pack_mode_seven_scene_objects_into_complete_oam_buffer_c64636:
    sta a:$0000,X
    stz a:$0002,X
    inx
    inx
    inx
    inx
    dey
    bne pack_mode_seven_scene_objects_into_complete_oam_buffer_c64636
    .i16
    ldy #$0008
pack_mode_seven_scene_objects_into_complete_oam_buffer_c64646:
    stz a:$0000,X
    stz a:$0002,X
    inx
    inx
    inx
    inx
    dey
    bne pack_mode_seven_scene_objects_into_complete_oam_buffer_c64646
    lda $4E
    beq pack_mode_seven_scene_objects_into_complete_oam_buffer_c646c2
    sta $30
    .i16
    ldy #$1100
    .i16
    ldx #$15E0
    .a16
    lda #$17E0
    sta $32
    stz $34
pack_mode_seven_scene_objects_into_complete_oam_buffer_c64666:
    lda a:$0001,Y
    sta $00,X
    lda a:$0003,Y
    sta $02,X
    sep #$20
    phx
    ldx $32
    lda $34
    beq pack_mode_seven_scene_objects_into_complete_oam_buffer_c646a8
    .a8
    cmp #$01
    beq pack_mode_seven_scene_objects_into_complete_oam_buffer_c6469f
    .a8
    cmp #$02
    beq pack_mode_seven_scene_objects_into_complete_oam_buffer_c64694
    lda a:$0000,Y
    ror
    ror
    ror
    .a8
    and #$C0
    ora $00,X
    sta $00,X
    inx
    stx $32
    stz $34
    bra pack_mode_seven_scene_objects_into_complete_oam_buffer_c646af
pack_mode_seven_scene_objects_into_complete_oam_buffer_c64694:
    lda a:$0000,Y
    asl
    asl
    asl
    asl
    ora $00,X
    bra pack_mode_seven_scene_objects_into_complete_oam_buffer_c646ab
pack_mode_seven_scene_objects_into_complete_oam_buffer_c6469f:
    lda a:$0000,Y
    asl
    asl
    ora $00,X
    bra pack_mode_seven_scene_objects_into_complete_oam_buffer_c646ab
pack_mode_seven_scene_objects_into_complete_oam_buffer_c646a8:
    lda a:$0000,Y
pack_mode_seven_scene_objects_into_complete_oam_buffer_c646ab:
    sta $00,X
    inc $34
pack_mode_seven_scene_objects_into_complete_oam_buffer_c646af:
    plx
    rep #$20
    txa
    clc
    .a16
    adc #$0004
    tax
    tya
    clc
    .a16
    adc #$0005
    tay
    dec $30
    bne pack_mode_seven_scene_objects_into_complete_oam_buffer_c64666
pack_mode_seven_scene_objects_into_complete_oam_buffer_c646c2:
    sep #$20
    rtl
