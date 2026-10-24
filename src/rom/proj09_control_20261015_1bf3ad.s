; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F3AD
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf3ad:
    .byte (LITERAL << 7) | (LITERAL << 6) | (LITERAL << 5) | (LITERAL << 4) | (LITERAL << 3) | (LITERAL << 2) | (LITERAL << 1) | (LITERAL << 0)
