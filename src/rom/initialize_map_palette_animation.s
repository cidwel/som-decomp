; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

decode_map_palette_animation_record = $BCD9

.segment "CODE"
.org $BC7E
initialize_map_palette_animation:
    sep #$30
    stz $9B
    lda $1C
    bmi initialize_map_palette_animation_c2bc87
    rtl
initialize_map_palette_animation_c2bc87:
    phb
    .a8
    lda #$7E
    pha
    plb
    lda $1C
    .a8
    and #$7F
    tax
    rep #$20
    .i8
    ldy #$00
initialize_map_palette_animation_c2bc95:
    lda a:$0600,Y
    sta a:$DE00,Y
    lda a:$0700,Y
    sta a:$DF00,Y
    iny
    iny
    bne initialize_map_palette_animation_c2bc95
    sep #$20
    lda f:$C80803,X
    sta $10
    stz $11
    lda f:$C80802,X
    tax
    rep #$20
    .a16
    lda #$D300
    sta $12
    sep #$20
    rep #$10
initialize_map_palette_animation_c2bcbf:
    lda f:$C8087B,X
    jsr decode_map_palette_animation_record
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    sep #$20
    inc $9B
    inx
    cpx $10
    bcc initialize_map_palette_animation_c2bcbf
    plb
    rtl
