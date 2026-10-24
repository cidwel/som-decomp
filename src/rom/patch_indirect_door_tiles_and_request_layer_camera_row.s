; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-door-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BB32
patch_indirect_door_tiles_and_request_layer_camera_row:
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$7F
    sta $02
    .a8
    lda #$41
    sta $82
    lda a:$E00B,X
    .i16
    ldy #$0000
    asl
    bcc patch_indirect_door_tiles_and_request_layer_camera_row_c0bb50
    .a8
    lda #$C0
    sta $82
    .i16
    ldy #$4000
patch_indirect_door_tiles_and_request_layer_camera_row_c0bb50:
    sty $00
    rep #$20
    lda a:$E002,X
    lsr
    lsr
    lsr
    lsr
    sta $04
    lda a:$E004,X
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $04
    clc
    adc $00
    sec
    .a16
    sbc #$0080
    sta $00
    sep #$20
    pla
    beq patch_indirect_door_tiles_and_request_layer_camera_row_c0bba3
    dec
    beq patch_indirect_door_tiles_and_request_layer_camera_row_c0bb98
    dec
    beq patch_indirect_door_tiles_and_request_layer_camera_row_c0bb81
    ldy $00
    dey
    sty $00
patch_indirect_door_tiles_and_request_layer_camera_row_c0bb81:
    .i16
    ldy #$0001
    .a8
    lda #$B2
    sta [$00]
    .a8
    lda #$B6
    sta [$00],Y
    .i16
    ldy #$0080
    .a8
    lda #$B3
    sta [$00],Y
    iny
    .a8
    lda #$B7
    bra patch_indirect_door_tiles_and_request_layer_camera_row_c0bbac
patch_indirect_door_tiles_and_request_layer_camera_row_c0bb98:
    .a8
    lda #$B6
    sta [$00]
    .i16
    ldy #$0080
    .a8
    lda #$B7
    bra patch_indirect_door_tiles_and_request_layer_camera_row_c0bbac
patch_indirect_door_tiles_and_request_layer_camera_row_c0bba3:
    .a8
    lda #$B2
    sta [$00]
    .i16
    ldy #$0080
    .a8
    lda #$B3
patch_indirect_door_tiles_and_request_layer_camera_row_c0bbac:
    sta [$00],Y
    lda $82
    asl
    rep #$20
    lda a:$E004,X
    bcc patch_indirect_door_tiles_and_request_layer_camera_row_c0bbc1
    sec
    sbc $AE
    bcs patch_indirect_door_tiles_and_request_layer_camera_row_c0bbc8
    adc $C6
    bra patch_indirect_door_tiles_and_request_layer_camera_row_c0bbc8
patch_indirect_door_tiles_and_request_layer_camera_row_c0bbc1:
    sec
    sbc $AA
    bcs patch_indirect_door_tiles_and_request_layer_camera_row_c0bbc8
    adc $C2
patch_indirect_door_tiles_and_request_layer_camera_row_c0bbc8:
    sep #$20
    sec
    .a8
    sbc #$02
    sta $83
    plb
    rts
