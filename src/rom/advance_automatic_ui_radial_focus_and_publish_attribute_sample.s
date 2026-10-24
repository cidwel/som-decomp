; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-radial.md.
.setcpu "65816"
.smart
.a8
.i16

advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte = $8FF3

.segment "CODE"
.org $8F24
advance_automatic_ui_radial_focus_and_publish_attribute_sample:
    rep #$30
    lda $F6
    .a16
    and #$00FF
    asl
    tax
    .a16
    eor #$01FE
    inc
    inc
    tay
    lda $F6
    .a16
    bit #$0100
    beq advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f3e
    phy
    phx
    ply
    plx
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f3e:
    lda a:$FD22,X
    sta $00
    lda a:$FD22,Y
    sta $02
    sep #$20
    lda $8E
    .a8
    and #$07
    bne advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f52
    dec $F8
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f52:
    lda $8E
    .a8
    and #$07
    bne advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f6b
    lda $86
    beq advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f6b
    dec
    sta $86
    .a8
    cmp #$10
    bne advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f6b
    .a8
    lda #$01
    sta $F2
    .a8
    lda #$0E
    sta $51
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f6b:
    lda $86
    sta a:$4202
    lda $01
    beq advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f78
    lda $86
    bra advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f84
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f78:
    lda $00
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f84:
    sta $00
    lda $03
    beq advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f8e
    lda $86
    bra advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f9a
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f8e:
    lda $02
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08f9a:
    sta $02
    stz $01
    stz $03
    rep #$20
    lda $F6
    .a16
    and #$0300
    beq advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fd7
    .a16
    cmp #$0100
    bne advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fb8
    lda $02
    .a16
    eor #$FFFF
    inc
    sta $02
    bra advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fd7
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fb8:
    .a16
    cmp #$0300
    bne advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fc7
    lda $00
    .a16
    eor #$FFFF
    inc
    sta $00
    bra advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fd7
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fc7:
    lda $02
    .a16
    eor #$FFFF
    inc
    sta $02
    lda $00
    .a16
    eor #$FFFF
    inc
    sta $00
advance_automatic_ui_radial_focus_and_publish_attribute_sample_c08fd7:
    lda $84
    clc
    adc $00
    sta $FA
    lda $88
    clc
    adc $02
    sta $FC
    sep #$20
    rep #$10
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte
    plb
    rts
