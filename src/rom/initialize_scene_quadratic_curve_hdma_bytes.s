; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

compute_scene_curve_square_over_one_hundred_forty_four = $AFA9

.segment "CODE"
.org $AF7D
initialize_scene_quadratic_curve_hdma_bytes:
    sep #$30
    .i8
    ldx #$07
initialize_scene_quadratic_curve_hdma_bytes_c2af81:
    lda f:$02AF75,X
    sta a:$0F00,X
    dex
    bpl initialize_scene_quadratic_curve_hdma_bytes_c2af81
    .i8
    ldx #$00
initialize_scene_quadratic_curve_hdma_bytes_c2af8d:
    txa
    .a8
    eor #$3F
    inc
    jsr compute_scene_curve_square_over_one_hundred_forty_four
    .a8
    ora #$E0
    sta a:$0F08,X
    inx
    .i8
    cpx #$40
    bcc initialize_scene_quadratic_curve_hdma_bytes_c2af8d
    .a8
    lda #$E0
initialize_scene_quadratic_curve_hdma_bytes_c2afa0:
    sta a:$0F08,X
    inx
    .i8
    cpx #$98
    bcc initialize_scene_quadratic_curve_hdma_bytes_c2afa0
    rtl
