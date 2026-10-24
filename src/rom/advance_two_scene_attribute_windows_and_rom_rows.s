; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8455
advance_two_scene_attribute_windows_and_rom_rows:
    rep #$20
    stx $00
    .a16
    lda #$0700
    sta $02
    .a16
    lda #$0500
    sta $04
    .i8
    cpy #$04
    beq advance_two_scene_attribute_windows_and_rom_rows_c0846b
    lsr $02
    lsr $04
advance_two_scene_attribute_windows_and_rom_rows_c0846b:
    ldx $00
    bne advance_two_scene_attribute_windows_and_rom_rows_c0847c
    lda $A8
    sec
    sbc $02
    sta $A8
    bcs advance_two_scene_attribute_windows_and_rom_rows_c08487
    dec $AA
    bra advance_two_scene_attribute_windows_and_rom_rows_c08487
advance_two_scene_attribute_windows_and_rom_rows_c0847c:
    lda $A8
    clc
    adc $02
    sta $A8
    bcc advance_two_scene_attribute_windows_and_rom_rows_c08487
    inc $AA
advance_two_scene_attribute_windows_and_rom_rows_c08487:
    lda $A9
    .a16
    and #$01F8
    cmp $B0
    bne advance_two_scene_attribute_windows_and_rom_rows_c08494
    stz $B4
    bra advance_two_scene_attribute_windows_and_rom_rows_c084e6
advance_two_scene_attribute_windows_and_rom_rows_c08494:
    sta $B0
    lsr
    lsr
    lsr
    sep #$20
    clc
    adc $00
    .a8
    and #$3F
    .a8
    cmp #$20
    rep #$20
    .a16
    ora #$5000
    bcc advance_two_scene_attribute_windows_and_rom_rows_c084af
    .a16
    and #$001F
    .a16
    ora #$5400
advance_two_scene_attribute_windows_and_rom_rows_c084af:
    sta $B6
    sep #$20
    lda $00
    bne advance_two_scene_attribute_windows_and_rom_rows_c084c4
    lda $BC
    sec
    .a8
    sbc #$01
    bcs advance_two_scene_attribute_windows_and_rom_rows_c084c0
    .a8
    adc #$E0
advance_two_scene_attribute_windows_and_rom_rows_c084c0:
    sta $BC
    bra advance_two_scene_attribute_windows_and_rom_rows_c084d8
advance_two_scene_attribute_windows_and_rom_rows_c084c4:
    lda $BC
    inc
    .a8
    cmp #$E0
    bcc advance_two_scene_attribute_windows_and_rom_rows_c084cd
    .a8
    sbc #$E0
advance_two_scene_attribute_windows_and_rom_rows_c084cd:
    sta $BC
    clc
    adc $00
    .a8
    cmp #$E0
    bcc advance_two_scene_attribute_windows_and_rom_rows_c084d8
    .a8
    sbc #$E0
advance_two_scene_attribute_windows_and_rom_rows_c084d8:
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    .a16
    adc #$5700
    sta $B4
advance_two_scene_attribute_windows_and_rom_rows_c084e6:
    .i8
    ldx #$A0
    stx a:$4203
    ldx $00
    bne advance_two_scene_attribute_windows_and_rom_rows_c084fc
    lda $AC
    sec
    sbc $04
    sta $AC
    bcs advance_two_scene_attribute_windows_and_rom_rows_c08507
    dec $AE
    bra advance_two_scene_attribute_windows_and_rom_rows_c08507
advance_two_scene_attribute_windows_and_rom_rows_c084fc:
    lda $AC
    clc
    adc $04
    sta $AC
    bcc advance_two_scene_attribute_windows_and_rom_rows_c08507
    inc $AE
advance_two_scene_attribute_windows_and_rom_rows_c08507:
    lda $AD
    .a16
    and #$01F8
    cmp $B2
    bne advance_two_scene_attribute_windows_and_rom_rows_c08513
    stz $B8
    rts
advance_two_scene_attribute_windows_and_rom_rows_c08513:
    sta $B2
    lsr
    lsr
    lsr
    sep #$20
    clc
    adc $00
    .a8
    and #$3F
    .a8
    cmp #$20
    rep #$20
    .a16
    ora #$5800
    bcc advance_two_scene_attribute_windows_and_rom_rows_c0852e
    .a16
    and #$001F
    .a16
    ora #$5C00
advance_two_scene_attribute_windows_and_rom_rows_c0852e:
    sta $BA
    sep #$20
    lda $00
    bne advance_two_scene_attribute_windows_and_rom_rows_c08543
    lda $BD
    sec
    .a8
    sbc #$01
    bcs advance_two_scene_attribute_windows_and_rom_rows_c0853f
    .a8
    adc #$A0
advance_two_scene_attribute_windows_and_rom_rows_c0853f:
    sta $BD
    bra advance_two_scene_attribute_windows_and_rom_rows_c08557
advance_two_scene_attribute_windows_and_rom_rows_c08543:
    lda $BD
    inc
    .a8
    cmp #$A0
    bcc advance_two_scene_attribute_windows_and_rom_rows_c0854c
    .a8
    sbc #$A0
advance_two_scene_attribute_windows_and_rom_rows_c0854c:
    sta $BD
    clc
    adc $00
    .a8
    cmp #$A0
    bcc advance_two_scene_attribute_windows_and_rom_rows_c08557
    .a8
    sbc #$A0
advance_two_scene_attribute_windows_and_rom_rows_c08557:
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    .a16
    adc #$4A00
    sta $B8
    rts
