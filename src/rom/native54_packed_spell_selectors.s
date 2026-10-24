; Target selector in high byte, spell ID in low byte; docs/boss-native54-cast.md.
.setcpu "65816"
.segment "CODE"
.org $485F
native54_packed_spell_selectors:
    .word $030B, $011F, $011E
