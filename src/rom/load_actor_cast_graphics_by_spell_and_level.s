; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_cast_secondary_graphics = $8634
routine_01c599 = $1C599

.segment "CODE"
.org $8654
load_actor_cast_graphics_by_spell_and_level:
    stx $14
    rep #$20
    pha
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    asl
    asl
    sta $08
    pla
    sep #$20
    .i16
    ldy #$0002
    xba
    sta $0A
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc load_actor_cast_graphics_by_spell_and_level_c1867b
    iny
    iny
    bit $0A
    bpl load_actor_cast_graphics_by_spell_and_level_c1867b
    iny
    iny
load_actor_cast_graphics_by_spell_and_level_c1867b:
    rep #$20
    tya
    clc
    adc $08
    tax
    lda f:$D02AA0,X
    ldx $14
    pha
    .a16
    and #$07FF
    asl
    asl
    asl
    sta $00
    asl
    adc $00
    tay
    pla
    .a16
    bit #$0800
    bne load_actor_cast_graphics_by_spell_and_level_c186af
    .a16
    lda #$007F
    sta $08
    .a16
    lda #$0000
    sta $00
    .a16
    lda #$00D4
    jsl f:routine_01c599
    ldx $14
    rts
load_actor_cast_graphics_by_spell_and_level_c186af:
    .a16
    lda #$0040
    sta $08
    .a16
    lda #$0000
    sta $00
    .a16
    lda #$00D4
    jsl f:routine_01c599
    jsr load_actor_cast_secondary_graphics
    ldx $14
    rts
