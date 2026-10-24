; Numeric index masks used by boss contact routines; see docs/graphics.md.
.setcpu "65816"
.segment "CODE"
.org $05F0
boss_contact_index_bit_masks:
.repeat 8, index
    .byte (1 << index)
.endrepeat
