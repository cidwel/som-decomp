; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16

publish_four_native_controller_button_label_tile_strips = $6E36

.segment "CODE"
.org $6E8F
retreat_native_controller_layout_button_assignment_and_swap:
    .a8
    lda #$FF
    sta a:$A175
    .i16
    ldx #$0004
retreat_native_controller_layout_button_assignment_and_swap_c76e97:
    lda a:$9C07,X
    sta a:$9C03,X
    dex
    bne retreat_native_controller_layout_button_assignment_and_swap_c76e97
    .a8
    lda #$00
    xba
    lda a:$A211
    tax
    lda a:$9C00,X
    clc
    adc a:$A175
    .a8
    and #$03
    sta a:$9C00,X
    pha
    txy
    .i16
    ldx #$FFFF
retreat_native_controller_layout_button_assignment_and_swap_c76eb8:
    inx
    cmp a:$9C04,X
    bne retreat_native_controller_layout_button_assignment_and_swap_c76eb8
    lda a:$9C04,Y
    sta a:$9C04,X
    pla
    sta a:$9C04,Y
    jsr publish_four_native_controller_button_label_tile_strips
    .a8
    lda #$02
    tsb a:$A20A
    .a8
    lda #$80
    tsb a:$A212
    rtl
