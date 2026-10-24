; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve.md.
.setcpu "65816"
.smart
.a8
.i16

select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $542E
dispatch_descriptor_twelve_variant_action:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$0042,X
    asl
    tax
    jmp ($5439,X)
