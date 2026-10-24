; Typed four-way fixed-point or eight-way integer vectors; docs/boss-descriptor-four-child-motion.md.
.setcpu "65816"
.segment "CODE"
.org $E400
descriptor_four_child_four_way_double_word_velocity:
    .word $1000, $0000, $0000, $0000, $0000, $0000, $1000, $0000
    .word $F000, $FFFF, $0000, $0000, $0000, $0000, $F000, $FFFF
