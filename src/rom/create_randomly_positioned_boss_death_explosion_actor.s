; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
copy_boss_palette_with_cpu_words = $26F9
draw_boss_frame_random_number = $300B

.segment "CODE"
.org $0C33
create_randomly_positioned_boss_death_explosion_actor:
    .a16
    lda #$0048
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    .a16
    lda #$0040
    jsr draw_boss_frame_random_number
    sta $99
    .a16
    lda #$0040
    jsr draw_boss_frame_random_number
    sta $9B
    ldx $87
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$0098,X
    .a16
    and #$0003
    .a16
    ora #$A920
    tay
    .i16
    ldx #$3197
    jsr allocate_boss_object_pool_slot
    bcs create_randomly_positioned_boss_death_explosion_actor_c20c86
    lda $99
    sec
    .a16
    sbc #$0020
    .a16
    eor #$FFFF
    inc
    clc
    adc $95
    sta a:$002B,X
    lda $9B
    sec
    .a16
    sbc #$0040
    clc
    adc $97
    sta a:$0032,X
create_randomly_positioned_boss_death_explosion_actor_c20c86:
    ldx $87
    rts
