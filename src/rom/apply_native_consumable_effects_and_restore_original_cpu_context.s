; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-consumable-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5536
apply_native_consumable_effects_and_restore_original_cpu_context:
    tax
    rep #$20
    lda a:$E182,Y
    beq apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    lda f:$D04152,X
    .a16
    and #$00FF
    clc
    adc a:$E1F3,Y
    sta a:$E1F3,Y
apply_native_consumable_effects_and_restore_original_cpu_context_c0554c:
    plp
    plb
    pld
    rtl
    rep #$20
    lda a:$E184,Y
    sta a:$E1F3,Y
    bra apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    rep #$20
    tax
    lda a:$E182,Y
    beq apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    sep #$20
    lda f:$D04152,X
    .a8
    and #$FF
    clc
    adc a:$E1F6,Y
    sta a:$E1F6,Y
    bra apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    .a8
    lda #$01
    sta a:$E1B2,Y
    sta a:$E1B3,Y
    sta a:$E1B4,Y
    sta a:$E1B5,Y
    sta a:$E1B6,Y
    .a8
    lda #$00
    sta a:$E190,Y
    lda a:$E191,Y
    .a8
    and #$80
    sta a:$E191,Y
apply_native_consumable_effects_and_restore_original_cpu_context_c05591:
    bra apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    lda a:$E191,Y
    .a8
    and #$7F
    sta a:$E191,Y
    rep #$20
    lda a:$E184,Y
    sta a:$E1F3,Y
    sta a:$E182,Y
    .a16
    lda #$0000
    sta a:$E1F1,Y
    sta a:$E1F5,Y
    jmp apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    .a8
    lda #$10
    eor a:$E191,Y
    sta a:$E191,Y
    lda a:$E191,Y
    .a8
    bit #$10
    beq apply_native_consumable_effects_and_restore_original_cpu_context_c05591
    .a8
    lda #$FF
    sta a:$E1B5,Y
    plp
    plb
    pld
    rtl
    .a8
    lda #$02
    eor a:$E191,Y
    sta a:$E191,Y
    lda a:$E191,Y
    .a8
    bit #$02
    beq apply_native_consumable_effects_and_restore_original_cpu_context_c05591
    .a8
    lda #$FF
    sta a:$E1B5,Y
    jmp apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
    .a8
    lda #$04
    ora a:$E191,Y
    sta a:$E191,Y
    jmp apply_native_consumable_effects_and_restore_original_cpu_context_c0554c
