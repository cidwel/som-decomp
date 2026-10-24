; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8890
publish_changed_scene_attribute_window_rows:
    .i8
    ldx #$01
    stx a:$2115
    .i8
    ldx #$C6
    stx a:$4374
    .a16
    lda #$1800
    sta a:$4370
    lda $B4
    beq publish_changed_scene_attribute_window_rows_c088b7
    sta a:$4372
    lda $B6
    sta a:$2116
    .a16
    lda #$0010
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
publish_changed_scene_attribute_window_rows_c088b7:
    lda $B8
    beq publish_changed_scene_attribute_window_rows_c088ce
    sta a:$4372
    lda $BA
    sta a:$2116
    .a16
    lda #$0010
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
publish_changed_scene_attribute_window_rows_c088ce:
    rts
