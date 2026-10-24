; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F35B
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf35b:
    .byte (HISTORY_TWO << 7) | (HISTORY_TWO << 6) | (HISTORY_TWO << 5) | (HISTORY_TWO << 4) | (LITERAL << 3) | (HISTORY_TWO << 2) | (LITERAL << 1) | (HISTORY_TWO << 0)
