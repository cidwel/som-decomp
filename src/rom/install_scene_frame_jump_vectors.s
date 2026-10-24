; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8350
install_scene_frame_jump_vectors:
    sep #$30
    .i8
    ldx #$07
install_scene_frame_jump_vectors_c08354:
    lda a:$835E,X
    sta a:$0100,X
    dex
    bpl install_scene_frame_jump_vectors_c08354
    rts
