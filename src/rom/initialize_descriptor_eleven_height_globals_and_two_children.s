; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $8AFC
initialize_descriptor_eleven_height_globals_and_two_children:
    .a16
    lda #$0060
    sta a:$0066,X
    sta a:$035A
    stz a:$0358
    stz a:$035C
    stz a:$007E,X
    .a16
    lda #$0020
    sta a:$00A5,X
    .i16
    ldy #$3901
    .i16
    ldx #$8DCA
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    .i16
    ldy #$2909
    .i16
    ldx #$8E38
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    rts
