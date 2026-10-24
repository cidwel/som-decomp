; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $272D
allocate_boss_palette_transition_object:
    pha
    phx
    phy
    .i16
    ldx #$274C
    .i16
    ldy #$6000
    jsr allocate_boss_object_pool_slot
    bcs allocate_boss_palette_transition_object_c22748
    pla
    sta a:$009E,X
    pla
    sta a:$009C,X
    pla
    sta a:$009A,X
    rts
allocate_boss_palette_transition_object_c22748:
    ply
    plx
    pla
    rts
