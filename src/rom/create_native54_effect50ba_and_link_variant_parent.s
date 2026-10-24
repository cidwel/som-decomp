; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $4535
create_native54_effect50ba_and_link_variant_parent:
    lda a:$0042,X
    sta $95
    .i16
    ldy #$2000
    .i16
    ldx #$50BA
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$0042,X
    lda $87
    sta a:$00B4,X
    rts
