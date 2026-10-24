; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8A79
alternate_ui_scene_palettes_and_configure_window:
    sep #$30
    bit $E3
    bvc alternate_ui_scene_palettes_and_configure_window_c08ac1
    lda $F5
    .a8
    bit #$01
    bne alternate_ui_scene_palettes_and_configure_window_c08ac1
    lda $F4
    bmi alternate_ui_scene_palettes_and_configure_window_c08ac1
    .a8
    bit #$22
    bne alternate_ui_scene_palettes_and_configure_window_c08a9c
    rep #$20
    .i8
    ldx #$7E
    stx a:$4374
    .a16
    lda #$DE00
    sta a:$4372
    bra alternate_ui_scene_palettes_and_configure_window_c08aa9
alternate_ui_scene_palettes_and_configure_window_c08a9c:
    rep #$20
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0600
    sta a:$4372
alternate_ui_scene_palettes_and_configure_window_c08aa9:
    .i8
    ldx #$00
    stx a:$2121
    .a16
    lda #$2200
    sta a:$4370
    .a16
    lda #$0200
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    sep #$20
alternate_ui_scene_palettes_and_configure_window_c08ac1:
    lda $2D
    beq alternate_ui_scene_palettes_and_configure_window_c08af1
    lsr
    bcs alternate_ui_scene_palettes_and_configure_window_c08ad1
    .a8
    lda #$00
    sta $2D
    sta a:$2123
    bra alternate_ui_scene_palettes_and_configure_window_c08af1
alternate_ui_scene_palettes_and_configure_window_c08ad1:
    .a8
    lda #$02
    sta a:$2123
    .a8
    lda #$01
    sta a:$212E
    inc $2D
    lda $2C
    .a8
    ora #$80
    sta $2C
    .i8
    ldx #$00
alternate_ui_scene_palettes_and_configure_window_c08ae5:
    lda a:$8AF8,X
    sta a:$4370,X
    inx
    .i8
    cpx #$08
    bcc alternate_ui_scene_palettes_and_configure_window_c08ae5
    rts
alternate_ui_scene_palettes_and_configure_window_c08af1:
    lda $2C
    .a8
    and #$7F
    sta $2C
    rts
