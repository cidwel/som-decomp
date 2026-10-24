; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

locate_selected_armor_with_nonzero_level = $D0D0DA
locate_selected_weapon_with_nonzero_level = $D0D0B0

.segment "CODE"
.org $CE5D
publish_selected_equipment_description_row:
    rep #$30
    sep #$20
    lda a:$1808
    .a8
    and #$01
    beq publish_selected_equipment_description_row_d0ce92
    jsl f:locate_selected_weapon_with_nonzero_level
    rep #$20
    txa
    .a16
    and #$00FF
    tax
    sep #$20
    asl
    pha
    asl
    clc
    adc $01,S
    .a8
    cmp #$2A
    bcc publish_selected_equipment_description_row_d0ce82
    sec
    .a8
    sbc #$06
publish_selected_equipment_description_row_d0ce82:
    sta $01,S
    lda a:$1878,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$03
    clc
    .a8
    adc #$03
    bra publish_selected_equipment_description_row_d0ceac
publish_selected_equipment_description_row_d0ce92:
    jsl f:locate_selected_armor_with_nonzero_level
    rep #$20
    txa
    .a16
    and #$00FF
    tax
    sep #$20
    asl
    pha
    asl
    clc
    adc $01,S
    sta $01,S
    lda a:$1878,X
    .a8
    and #$03
publish_selected_equipment_description_row_d0ceac:
    clc
    adc $01,S
    sta $01,S
    pla
    sta a:$1839
    sta a:$19F1
    txa
    sta a:$1846
    lda a:$1839
    rep #$30
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    asl
    asl
    tax
    sep #$20
    lda f:$D02ADF,X
    sta a:$1843
    lda f:$D02AD8,X
    sta a:$1842
    lda a:$1839
    rtl
