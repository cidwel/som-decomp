; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $3E7F
launch_mantis_ant_homing_projectile:
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$00A9,X
    sta $9D
    stx $9F
    lda a:$00AB,X
    asl
    asl
    tax
    lda f:$DCE028,X
    sta $99
    lda f:$DCE02A,X
    sta $9B
    .i16
    ldy #$2801
    .i16
    ldx #$3ED6
    jsr allocate_boss_object_pool_slot
    bcs launch_mantis_ant_homing_projectile_c23ed3
    lda $95
    sec
    .a16
    sbc #$000C
    sta a:$002B,X
    lda $97
    clc
    .a16
    adc #$0004
    sta a:$0032,X
    lda $99
    sta a:$003C,X
    lda $9B
    sta a:$0040,X
    lda $9D
    sta a:$00A9,X
    lda $9F
    sta a:$00B0,X
launch_mantis_ant_homing_projectile_c23ed3:
    ldx $87
    rts
