; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F361
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf361:
    .byte (HISTORY_TWO << 7) | (HISTORY_TWO << 6) | (HISTORY_TWO << 5) | (HISTORY_TWO << 4) | (HISTORY_TWO << 3) | (HISTORY_TWO << 2) | (HISTORY_TWO << 1) | (HISTORY_TWO << 0)
    .byte (HISTORY_TWO << 7) | (LITERAL << 6) | (HISTORY_TWO << 5) | (LITERAL << 4) | (LITERAL << 3) | (HISTORY_TWO << 2) | (HISTORY_TWO << 1) | (HISTORY_TWO << 0)
