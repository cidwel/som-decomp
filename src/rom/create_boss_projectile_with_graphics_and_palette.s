; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
copy_boss_palette_colors_from_rom = $2700
load_boss_projectile_graphics_list = $2476

.segment "CODE"
.org $33BE
create_boss_projectile_with_graphics_and_palette:
    sta $9D
    sty $9F
    lda a:$002B,X
    clc
    adc $95
    sta $95
    lda a:$0066,X
    lsr
    sta $99
    lda a:$0032,X
    clc
    adc $97
    sec
    sbc $99
    sta $97
    stx $99
    tya
    .a16
    and #$0003
    xba
    asl
    clc
    .a16
    adc #$E000
    sta $9B
    lda a:$0098,X
    .a16
    and #$0003
    .a16
    ora #$AA20
    tay
    lda $9D
    asl
    tax
    lda f:$DCE683,X
    tax
    jsr allocate_boss_object_pool_slot
    bcs create_boss_projectile_with_graphics_and_palette_c23437
    lda $A1
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    lda $99
    sta a:$00B0,X
    lda $9B
    sta a:$00B2,X
    lda $9F
    sta a:$00B8,X
    lda $9D
    sta a:$00B4,X
    phx
    jsr load_boss_projectile_graphics_list
    lda $9D
    asl
    tax
    lda f:$DCE6C1,X
    plx
    sta a:$00B6,X
    .i16
    ldx #$000F
    jsr copy_boss_palette_colors_from_rom
create_boss_projectile_with_graphics_and_palette_c23437:
    rts
