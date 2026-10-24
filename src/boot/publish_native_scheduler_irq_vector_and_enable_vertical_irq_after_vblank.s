; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-scheduler-irq-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A1E2
publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$00C0
    sta f:$004209
    sep #$20
    .a8
    lda #$5C
    sta f:$000104
    .a8
    lda #$66
    sta f:$000105
    .a8
    lda #$A2
    sta f:$000106
    .a8
    lda #$7E
    sta f:$000107
    .a8
    lda #$40
    sta f:$000100
    inc a:$008C
    lda f:$004211
    lda f:$004210
publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank_a221:
    lda f:$004212
    .a8
    bit #$80
    bne publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank_a221
publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank_a229:
    lda f:$004212
    .a8
    bit #$80
    beq publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank_a229
    lda a:$0090
    .a8
    ora #$20
    sta a:$0090
    sta f:$004200
    plb
    plp
    pld
    rts
