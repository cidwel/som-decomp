; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F259
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf259:
    .byte (LITERAL << 7) | (HISTORY_TWO << 6) | (HISTORY_TWO << 5) | (HISTORY_TWO << 4) | (HISTORY_TWO << 3) | (HISTORY_TWO << 2) | (HISTORY_TWO << 1) | (HISTORY_TWO << 0)
