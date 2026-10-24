; Typed four-way fixed-point or eight-way integer vectors; docs/boss-descriptor-four-child-motion.md.
.setcpu "65816"
.segment "CODE"
.org $E420
descriptor_four_child_eight_way_integer_velocity:
    .word $0002, $0000, $0002, $0002, $0000, $0002, $FFFE, $0002
    .word $FFFE, $0000, $FFFE, $FFFE, $0000, $FFFE, $0002, $FFFE
