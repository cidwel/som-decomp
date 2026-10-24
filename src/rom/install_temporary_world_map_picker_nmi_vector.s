; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A638
install_temporary_world_map_picker_nmi_vector:
    sep #$30
    .i8
    ldx #$03
install_temporary_world_map_picker_nmi_vector_c0a63c:
    lda a:$A646,X
    sta a:$0100,X
    dex
    bpl install_temporary_world_map_picker_nmi_vector_c0a63c
    rts
