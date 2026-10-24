; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
load_leaping_boss_projectile_palette_58 = $7273

.segment "CODE"
.org $73E6
launch_boss_projectile_with_mirrored_horizontal_velocity:
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$00A9,X
    sta $9D
    stx $9F
    .a16
    lda #$001E
    sta $99
    .a16
    lda #$0004
    sta $A1
    .a16
    lda #$FFFC
    sta $A3
    lda a:$0098,X
    .a16
    bit #$0040
    beq launch_boss_projectile_with_mirrored_horizontal_velocity_c2741c
    lda $99
    eor $C7
    inc
    sta $99
    lda $A1
    eor $C7
    inc
    sta $A1
launch_boss_projectile_with_mirrored_horizontal_velocity_c2741c:
    .a16
    lda #$FFD8
    sta $9B
    .i16
    ldy #$B801
    .i16
    ldx #$7456
    jsr allocate_boss_object_pool_slot
    bcs launch_boss_projectile_with_mirrored_horizontal_velocity_c27453
    lda $95
    clc
    adc $99
    sta a:$002B,X
    lda $97
    clc
    adc $9B
    sta a:$0032,X
    lda $9D
    sta a:$00A9,X
    lda $A1
    sta a:$003C,X
    lda $A3
    sta a:$0040,X
    lda $9F
    sta a:$00B0,X
    jsr load_leaping_boss_projectile_palette_58
launch_boss_projectile_with_mirrored_horizontal_velocity_c27453:
    ldx $87
    rts
