; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AD17
initialize_complete_world_map_survey_background_and_color_planes:
    sep #$30
    .a8
    lda #$80
    sta a:$2115
    tay
    .i8
    ldx #$CE
initialize_complete_world_map_survey_background_and_color_planes_c0ad21:
    stz $00,X
    dex
    bne initialize_complete_world_map_survey_background_and_color_planes_c0ad21
    stz a:$210D
    stz a:$210D
    stz a:$210E
    stz a:$210E
    .a8
    lda #$03
    sta a:$2105
    stz a:$2131
    .a8
    lda #$78
    sta a:$2107
    stz a:$210B
    .a8
    lda #$01
    sta a:$2130
    .a8
    lda #$11
    sta a:$212C
    .a8
    lda #$80
    sta a:$2115
    stz a:$4374
    rep #$20
    stz $00
    stz a:$2116
    stz a:$4372
    .a16
    lda #$1809
    sta a:$4370
    .a16
    lda #$F000
    sta a:$4375
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    rep #$30
    .a16
    lda #$7800
    sta a:$2116
    .i16
    ldx #$0000
initialize_complete_world_map_survey_background_and_color_planes_c0ad7c:
    stx a:$2118
    inx
    .i16
    cpx #$03C0
    bcc initialize_complete_world_map_survey_background_and_color_planes_c0ad7c
    .i16
    ldx #$0000
initialize_complete_world_map_survey_background_and_color_planes_c0ad88:
    stx a:$2118
    inx
    .i16
    cpx #$0040
    bcc initialize_complete_world_map_survey_background_and_color_planes_c0ad88
    sep #$30
    .i8
    ldx #$00
initialize_complete_world_map_survey_background_and_color_planes_c0ad95:
    lda f:$C64780,X
    pha
    .a8
    and #$07
    sta f:$7FD800,X
    pla
    pha
    .a8
    and #$38
    sta f:$7FD900,X
    pla
    .a8
    and #$C0
    lsr
    lsr
    sta f:$7FDA00,X
    inx
    .i8
    cpx #$C0
    bne initialize_complete_world_map_survey_background_and_color_planes_c0ad95
    .a8
    lda #$00
    sta f:$7FD800,X
    sta f:$7FD900,X
    sta f:$7FDA00,X
    .a8
    lda #$F1
    sta a:$2121
    .a8
    lda #$FF
    sta a:$2122
    sta a:$2122
    .a8
    lda #$1F
    sta a:$2122
    stz a:$2122
    stz a:$2121
    stz a:$2122
    stz a:$2122
    rts
