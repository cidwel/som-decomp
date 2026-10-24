; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6A98
follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth:
    ldx $87
    ldy a:$00B0,X
    lda a:$00B2,X
    asl
    asl
    tax
    lda a:$002B,Y
    sta $95
    lda a:$0032,Y
    sta $97
    lda a:$0066,Y
    sta $99
    lda a:$0022,Y
    sta $9B
    lda f:$C26B13,X
    sta $9D
    lda f:$C26B15,X
    sta $9F
    lda a:$0098,Y
    .a16
    bit #$0040
    beq follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth_c26ad2
    lda $9D
    eor $C7
    inc
    sta $9D
follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth_c26ad2:
    ldx $87
    sep #$20
    stz $A2
    lda a:$0089,Y
    sta $A1
    rep #$20
    lda $95
    clc
    adc $9D
    sta a:$002B,X
    lda $97
    clc
    adc $9F
    adc $A1
    sta a:$0032,X
    lda $99
    sta a:$0066,X
    lda a:$000B,Y
    sta a:$000B,X
    lda a:$00B2,X
    bne follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth_c26b09
    lda $9B
    clc
    .a16
    adc #$0008
    bra follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth_c26b0f
follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth_c26b09:
    lda $9B
    sec
    .a16
    sbc #$0008
follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth_c26b0f:
    sta a:$0022,X
    rts
