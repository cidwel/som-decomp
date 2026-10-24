; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
prepare_animation_object_mirrored_position = $1978

.segment "CODE"
.org $1A3E
create_animation_object_with_explicit_flags:
    stz $9A
    stz $9C
    lda [$76],Y
    iny
    iny
    sta $97
    lda [$76],Y
    iny
    iny
    sta $A5
    jsr prepare_animation_object_mirrored_position
    phy
    ldy $A5
    .i16
    ldx #$31D4
    jsr allocate_boss_object_pool_slot
    lda $97
    sta a:$009A,X
    lda $9F
    sta a:$002B,X
    lda $A1
    sta a:$0032,X
    lda $9D
    sta a:$0066,X
    lda $A3
    sta a:$00B0,X
    lda $99
    sta a:$00B2,X
    lda $9B
    sta a:$00B4,X
    ldx $87
    ply
    rts
