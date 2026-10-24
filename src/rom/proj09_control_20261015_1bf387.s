; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F387
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf387:
    .byte (LITERAL << 7) | (LITERAL << 6) | (LITERAL << 5) | (HISTORY_TWO << 4) | (HISTORY_TWO << 3) | (HISTORY_TWO << 2) | (LITERAL << 1) | (HISTORY_TWO << 0)
