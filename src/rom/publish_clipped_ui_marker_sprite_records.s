; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B247
publish_clipped_ui_marker_sprite_records:
publish_clipped_ui_marker_sprite_records_c2b247:
    sep #$20
    lda f:$C20000,X
    bpl publish_clipped_ui_marker_sprite_records_c2b256
    clc
    adc $09
    bcc publish_clipped_ui_marker_sprite_records_c2b27e
    bcs publish_clipped_ui_marker_sprite_records_c2b25b
publish_clipped_ui_marker_sprite_records_c2b256:
    clc
    adc $09
    bcs publish_clipped_ui_marker_sprite_records_c2b27e
publish_clipped_ui_marker_sprite_records_c2b25b:
    xba
    lda f:$C20001,X
    bpl publish_clipped_ui_marker_sprite_records_c2b269
    clc
    adc $08
    bcc publish_clipped_ui_marker_sprite_records_c2b27e
    bcs publish_clipped_ui_marker_sprite_records_c2b26e
publish_clipped_ui_marker_sprite_records_c2b269:
    clc
    adc $08
    bcs publish_clipped_ui_marker_sprite_records_c2b27e
publish_clipped_ui_marker_sprite_records_c2b26e:
    rep #$20
    sta a:$0800,Y
    lda f:$C20002,X
    sta a:$0802,Y
    iny
    iny
    iny
    iny
publish_clipped_ui_marker_sprite_records_c2b27e:
    inx
    inx
    inx
    inx
    dec $02
    bne publish_clipped_ui_marker_sprite_records_c2b247
    rts
