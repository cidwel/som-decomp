; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

select_active_ui_party_icon_composition = $9E25

.segment "CODE"
.org $9DFC
advance_and_publish_automatic_ui_party_icons:
    rep #$10
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    lda $F4
    .a8
    and #$03
    bne advance_and_publish_automatic_ui_party_icons_c09e18
    lda $9C
    clc
    .a8
    adc #$30
    .a8
    cmp #$C0
    bcc advance_and_publish_automatic_ui_party_icons_c09e16
    .a8
    lda #$00
advance_and_publish_automatic_ui_party_icons_c09e16:
    sta $9C
advance_and_publish_automatic_ui_party_icons_c09e18:
    .a8
    lda #$E7
    sta $9D
    stz $7C
    stz $7D
    jsr select_active_ui_party_icon_composition
    plb
    rts
