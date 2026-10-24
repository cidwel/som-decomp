; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F294
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf294:
    .byte (LITERAL << 7) | (HISTORY_TWO << 6) | (HISTORY_TWO << 5) | (HISTORY_TWO << 4) | (LITERAL << 3) | (HISTORY_TWO << 2) | (LITERAL << 1) | (LITERAL << 0)
