; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $6DE7
allocate_descriptor_eight_child_and_initialize_child_phase:
    stx $95
    .i16
    ldx #$6F9C
    .i16
    ldy #$2909
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    stz a:$007E,X
    rts
