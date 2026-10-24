; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

expand_boss_loader_resource_to_bus = $24F1

.segment "CODE"
.org $2476
load_boss_projectile_graphics_list:
    tax
    lda f:$D0BAC0,X
    .a16
    and #$00FF
    asl
    asl
    sta $46
load_boss_projectile_graphics_list_c22482:
    ldx $46
    lda f:$D0BADF,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq load_boss_projectile_graphics_list_c224c2
    asl
    tax
    lda f:$D0BB0C,X
    sta $79
    .a16
    lda #$0400
    sta $68
    lda $46
    .a16
    and #$0003
    xba
    asl
    asl
    clc
    .a16
    adc #$7000
    sta $7C
    sep #$20
    .a8
    lda #$DB
    sta $7B
    .a8
    lda #$7F
    sta $7E
    rep #$20
    stz $6A
    stz $6C
    jsr expand_boss_loader_resource_to_bus
    inc $46
    bra load_boss_projectile_graphics_list_c22482
load_boss_projectile_graphics_list_c224c2:
    rts
