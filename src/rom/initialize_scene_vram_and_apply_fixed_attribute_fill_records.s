; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-vram-initialization.md.
.setcpu "65816"
.smart
.a8
.i16

configure_and_trigger_dma_seven_from_word_arguments = $F9E1

.segment "CODE"
.org $F96A
initialize_scene_vram_and_apply_fixed_attribute_fill_records:
    rep #$20
    sep #$10
    .i8
    ldy #$80
    sty a:$2115
    .i8
    ldy #$00
    sty a:$4374
    .a16
    lda #$0000
    sta a:$4372
    .a16
    lda #$1809
    sta a:$4370
    stz $00
    .a16
    lda #$5000
    sta a:$2116
    .a16
    lda #$1000
    sta a:$4375
    .i8
    ldy #$80
    sty a:$420B
    .a16
    lda #$1908
    sta a:$4370
    .i8
    ldx #$00
initialize_scene_vram_and_apply_fixed_attribute_fill_records_c1f99f:
    lda f:$01F9F2,X
    sta $00
    lda f:$01F9F3,X
    sta a:$2116
    lda f:$01F9F5,X
    sta a:$4375
    sty a:$420B
    txa
    clc
    .a16
    adc #$0005
    tax
    .i8
    cpx #$1E
    bcc initialize_scene_vram_and_apply_fixed_attribute_fill_records_c1f99f
    sep #$20
    .a8
    lda #$80
    sta a:$2115
    .a8
    lda #$C6
    sta a:$4374
    rep #$30
    .a16
    lda #$4000
    sta a:$2116
    .a16
    lda #$1801
    .i16
    ldx #$2000
    .i16
    ldy #$1000
    jsr configure_and_trigger_dma_seven_from_word_arguments
    rts
