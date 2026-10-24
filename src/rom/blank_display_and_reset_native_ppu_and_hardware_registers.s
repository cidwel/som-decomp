; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-to-map-reset.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B5E7
blank_display_and_reset_native_ppu_and_hardware_registers:
    sep #$30
    .a8
    lda #$8F
    sta a:$2100
    stz a:$4200
    stz a:$2101
    stz a:$2102
    stz a:$2103
    .i8
    ldx #$00
    txa
blank_display_and_reset_native_ppu_and_hardware_registers_c2b5fd:
    sta a:$2105,X
    inx
    .i8
    cpx #$08
    bne blank_display_and_reset_native_ppu_and_hardware_registers_c2b5fd
    .i8
    ldx #$00
blank_display_and_reset_native_ppu_and_hardware_registers_c2b607:
    sta a:$210D,X
    sta a:$210D,X
    inx
    .i8
    cpx #$08
    bcc blank_display_and_reset_native_ppu_and_hardware_registers_c2b607
    .i8
    ldx #$80
    stx a:$2115
    stx a:$2116
    stx a:$2117
    sta a:$2121
    .i8
    ldx #$00
blank_display_and_reset_native_ppu_and_hardware_registers_c2b622:
    sta a:$2123,X
    sta a:$4202,X
    inx
    .i8
    cpx #$0C
    bcc blank_display_and_reset_native_ppu_and_hardware_registers_c2b622
    .i8
    ldx #$00
    sta a:$2131
    sta a:$2133
    sta a:$211C
    sta a:$211C
    sta a:$211D
    sta a:$211D
    sta a:$211F
    sta a:$211F
    .a8
    lda #$01
    sta a:$211B
    stx a:$211B
    sta a:$211E
    stx a:$211E
    .a8
    lda #$30
    sta a:$2130
    .a8
    lda #$E0
    sta a:$2132
    .a8
    lda #$FF
    sta a:$4201
    rtl
