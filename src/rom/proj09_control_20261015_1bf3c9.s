; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F3C9
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf3c9:
    .byte (LITERAL << 7) | (LITERAL << 6) | (HISTORY_TWO << 5) | (HISTORY_TWO << 4) | (LITERAL << 3) | (LITERAL << 2) | (HISTORY_TWO << 1) | (HISTORY_TWO << 0)
