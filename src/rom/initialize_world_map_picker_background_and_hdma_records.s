; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A841
initialize_world_map_picker_background_and_hdma_records:
    sep #$30
    .i8
    ldy #$06
    stz a:$211B
    sty a:$211B
    .i8
    ldy #$08
    stz a:$211C
    stz a:$211C
    stz a:$211D
    stz a:$211D
    stz a:$211E
    sty a:$211E
    .a8
    lda #$80
    sta a:$211A
    .a8
    lda #$01
    sta a:$2130
    .a8
    lda #$11
    sta a:$212C
    .a8
    lda #$80
    sta a:$2115
    stz a:$2116
    stz a:$2117
    .a8
    lda #$00
    tay
    .i8
    ldx #$CE
initialize_world_map_picker_background_and_hdma_records_c0a87e:
    sta $00,X
    dex
    bne initialize_world_map_picker_background_and_hdma_records_c0a87e
initialize_world_map_picker_background_and_hdma_records_c0a883:
    .i8
    ldy #$40
    lda f:$C64780,X
initialize_world_map_picker_background_and_hdma_records_c0a889:
    sta a:$2119
    dey
    bne initialize_world_map_picker_background_and_hdma_records_c0a889
    inc
    inx
    .i8
    cpx #$C0
    bcc initialize_world_map_picker_background_and_hdma_records_c0a883
    .i8
    ldy #$40
initialize_world_map_picker_background_and_hdma_records_c0a897:
    stz a:$2119
    dey
    bne initialize_world_map_picker_background_and_hdma_records_c0a897
    .a8
    lda #$F1
    sta a:$2121
    .a8
    lda #$FF
    sta a:$2122
    sta a:$2122
    stz a:$2121
    stz a:$2122
    stz a:$2122
    sep #$20
    .a8
    lda #$02
    stz a:$211F
    sta a:$211F
    stz a:$2120
    sta a:$2120
    .a8
    lda #$07
    sta a:$2105
    .a8
    lda #$00
    sta a:$2131
    .i8
    ldx #$80
    .i8
    ldy #$90
    .a8
    lda #$01
    stx a:$210D
    sta a:$210D
    sty a:$210E
    sta a:$210E
    rep #$20
    .i8
    ldx #$00
    .i8
    ldy #$7E
initialize_world_map_picker_background_and_hdma_records_c0a8e5:
    lda a:$A961,X
    asl
    asl
    asl
    sta a:$1180,X
    sta a:$1100,Y
    dey
    dey
    inx
    inx
    .i8
    cpx #$80
    bcc initialize_world_map_picker_background_and_hdma_records_c0a8e5
    .i8
    ldx #$00
initialize_world_map_picker_background_and_hdma_records_c0a8fb:
    lda a:$A932,X
    sta a:$1080,X
    lda a:$A93F,X
    sta a:$1200,X
    inx
    .i8
    cpx #$30
    bcc initialize_world_map_picker_background_and_hdma_records_c0a8fb
    .i8
    ldx #$00
initialize_world_map_picker_background_and_hdma_records_c0a90e:
    lda a:$A92A,X
    sta a:$4340,X
    inx
    inx
    .i8
    cpx #$08
    bcc initialize_world_map_picker_background_and_hdma_records_c0a90e
    sep #$20
    .a8
    lda #$B0
    sta a:$2121
    stz a:$2122
    .a8
    lda #$70
    sta a:$2122
    rts
