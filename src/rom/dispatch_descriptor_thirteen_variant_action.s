; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16

select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $675A
dispatch_descriptor_thirteen_variant_action:
    jsr select_nearest_living_target_and_eight_way_direction
    lda a:$0042,X
    asl
    tax
    jmp ($6765,X)
