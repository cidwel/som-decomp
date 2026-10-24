; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

cycle_descriptor_eight_child_end_palette_slot = $7081

.segment "CODE"
.org $701A
dispatch_descriptor_eight_child_animation_palette_cycle:
    lda a:$0096,X
    .a16
    bit #$0001
    beq dispatch_descriptor_eight_child_animation_palette_cycle_c2703a
    lda a:$009A,Y
    beq dispatch_descriptor_eight_child_animation_palette_cycle_c2703a
    lda a:$009A,X
    .a16
    cmp #$0133
    beq cycle_descriptor_eight_child_end_palette_slot
    sec
    .a16
    sbc #$00FA
    bmi dispatch_descriptor_eight_child_animation_palette_cycle_c2703a
    asl
    tax
    jmp ($703B,X)
dispatch_descriptor_eight_child_animation_palette_cycle_c2703a:
    rts
