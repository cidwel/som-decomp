; Numeric projectile-child selectors; docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.segment "CODE"
.org $9BA0
directional_spell_sector_fractional_integer_velocities:
    .word $0000, $0003, $0000, $0000, $991B, $0002, $8000, $0001
    .word $1F0E, $0002, $1F0E, $0002, $8000, $0001, $991B, $0002
    .word $0000, $0000, $0000, $0003, $8000, $FFFE, $991B, $0002
    .word $E0F2, $FFFD, $1F0E, $0002, $66E5, $FFFD, $8000, $0001
    .word $0000, $FFFD, $0000, $0000, $66E5, $FFFD, $8000, $FFFE
    .word $E0F2, $FFFD, $E0F2, $FFFD, $8000, $FFFE, $66E5, $FFFD
    .word $0000, $0000, $0000, $FFFD, $8000, $0001, $66E5, $FFFD
    .word $1F0E, $0002, $E0F2, $FFFD, $991B, $0002, $8000, $FFFE
