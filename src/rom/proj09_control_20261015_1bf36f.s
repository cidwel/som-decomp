; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F36F
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf36f:
    .byte (LITERAL << 7) | (LITERAL << 6) | (HISTORY_TWO << 5) | (HISTORY_TWO << 4) | (HISTORY_TWO << 3) | (HISTORY_TWO << 2) | (HISTORY_TWO << 1) | (HISTORY_TWO << 0)
