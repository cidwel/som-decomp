; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

test_both_party_charge_globals = $499A

.segment "CODE"
.org $48E6
read_appearance_level_and_party_charge:
    .a8
    lda #$00
    xba
    stx $D0
    lda a:$E1E4,X
    sta $D8
    lda a:$E1FB,X
    bmi read_appearance_level_and_party_charge_c048f9
    .a8
    lda #$01
    sta $D8
read_appearance_level_and_party_charge_c048f9:
    lda $D8
    lsr
    sta $D0
    ldy $D0
    lda a:$E1C0,Y
    sta $D4
    .a8
    lda #$01
    bit $D8
    bne read_appearance_level_and_party_charge_c04913
    lsr $D4
    lsr $D4
    lsr $D4
    lsr $D4
read_appearance_level_and_party_charge_c04913:
    lda $D4
    .a8
    and #$0F
    sta a:$E19C,X
    lda $BA
    beq read_appearance_level_and_party_charge_c0491f
read_appearance_level_and_party_charge_c0491e:
    rts
read_appearance_level_and_party_charge_c0491f:
    stz a:$CC76
    jsr test_both_party_charge_globals
    bcc read_appearance_level_and_party_charge_c0491e
    lda a:$E1E4
    .a8
    cmp #$01
    beq read_appearance_level_and_party_charge_c0492f
    rts
read_appearance_level_and_party_charge_c0492f:
    .a8
    lda #$80
    sta a:$E195,X
    rep #$20
    stz $A4
    .i16
    ldy #$0007
read_appearance_level_and_party_charge_c0493b:
    lda a:$E1D0,Y
    .a16
    and #$00FF
    clc
    adc $A4
    sta $A4
    dey
    bpl read_appearance_level_and_party_charge_c0493b
    sta f:$004204
    sep #$20
    .a8
    lda #$64
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004214
    sta $A4
    .a8
    lda #$07
    sta $A6
    .a8
    lda #$00
    sta $AA
    xba
read_appearance_level_and_party_charge_c0496c:
    lda $A6
    lsr
    php
    tay
    lda a:$E1C0,Y
    sta $A8
    plp
    bcs read_appearance_level_and_party_charge_c04981
    lsr $A8
    lsr $A8
    lsr $A8
    lsr $A8
read_appearance_level_and_party_charge_c04981:
    lda $A8
    .a8
    and #$0F
    clc
    adc $AA
    sta $AA
    dec $A6
    bpl read_appearance_level_and_party_charge_c0496c
    lda $AA
    lsr
    lsr
    lsr
    clc
    adc $A4
    sta a:$CC76
    rts
