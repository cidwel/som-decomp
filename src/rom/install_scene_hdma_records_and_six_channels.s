; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ADAA
install_scene_hdma_records_and_six_channels:
    phb
    .i8
    ldx #$02
    phx
    plb
    .i8
    ldx #$26
install_scene_hdma_records_and_six_channels_c2adb1:
    lda f:$02AD52,X
    sta a:$0FD8,X
    dex
    dex
    bpl install_scene_hdma_records_and_six_channels_c2adb1
    .i8
    ldx #$06
install_scene_hdma_records_and_six_channels_c2adbe:
    lda f:$02AD7A,X
    sta a:$4300,X
    lda f:$02AD82,X
    sta a:$4310,X
    lda f:$02AD8A,X
    sta a:$4320,X
    lda f:$02AD92,X
    sta a:$4330,X
    lda f:$02AD9A,X
    sta a:$4340,X
    lda f:$02ADA2,X
    sta a:$4350,X
    dex
    dex
    bpl install_scene_hdma_records_and_six_channels_c2adbe
    plb
    rtl
