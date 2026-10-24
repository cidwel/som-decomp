; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-font-palette.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_palette_slot = $BBAB
copy_far_stack_arguments = $C44E
copy_palette_colours = $BC9A
queue_palette_upload = $BBFE

.segment "CODE"
.org $9716
copy_native_title_font_and_register_eight_upper_palette_slots:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .i16
    ldy #$00C0
    phy
    .a8
    lda #$7E
    pha
    .i16
    ldy #$5000
    phy
    .a8
    lda #$7F
    pha
    phx
    jsr copy_far_stack_arguments
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    sep #$20
    .a8
    lda #$08
    sta $01
copy_native_title_font_and_register_eight_upper_palette_slots_9744:
    .a8
    lda #$08
    jsr allocate_palette_slot
    dec $01
    bne copy_native_title_font_and_register_eight_upper_palette_slots_9744
    phx
    .a8
    lda #$7E
    .i16
    ldy #$5140
    xba
    .a8
    lda #$87
    jsr copy_palette_colours
    plx
    jsr queue_palette_upload
    plb
    pla
    pla
    plp
    pld
    rts
