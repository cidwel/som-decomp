; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A801
blink_and_upload_four_world_map_picker_cursor_objects:
    .a16
    bit #$0010
    beq blink_and_upload_four_world_map_picker_cursor_objects_c2a817
    .a16
    lda #$E0FF
    sta a:$0800
    sta a:$0804
    sta a:$0808
    sta a:$0810
    bra blink_and_upload_four_world_map_picker_cursor_objects_c2a82c
blink_and_upload_four_world_map_picker_cursor_objects_c2a817:
    .a16
    lda #$6070
    sta a:$0800
    .a16
    lda #$6080
    sta a:$0804
    .a16
    lda #$7070
    sta a:$0808
    .a16
    lda #$7080
blink_and_upload_four_world_map_picker_cursor_objects_c2a82c:
    sta a:$080C
    .a16
    lda #$0000
    sta a:$2102
    .a16
    lda #$0800
    sta a:$4372
    .a16
    lda #$0400
    sta a:$4370
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0010
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    rtl
