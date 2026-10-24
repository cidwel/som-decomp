; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $63D4
allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases:
    lda $87
    sta $95
    .a16
    lda #$0000
    sta $1A
allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases_c263dd:
    .i16
    ldy #$A901
    .i16
    ldx #$641D
    jsr allocate_boss_object_pool_slot
    bcs allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases_c2641c
    txy
    lda $1A
    asl
    asl
    tax
    lda f:$DCE2C3,X
    sta a:$00B6,Y
    lda f:$DCE2C5,X
    sta a:$00B8,Y
    lda $1A
    asl
    tax
    lda f:$DCE2DB,X
    sta a:$00B0,Y
    lda f:$DCE2E7,X
    sta a:$00B2,Y
    lda $95
    sta a:$00BA,Y
    inc $1A
    lda $1A
    .a16
    cmp #$0006
    bne allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases_c263dd
allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases_c2641c:
    rts
