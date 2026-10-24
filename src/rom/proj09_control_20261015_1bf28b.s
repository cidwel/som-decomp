; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F28B
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf28b:
    .byte (LITERAL << 7) | (LITERAL << 6) | (LITERAL << 5) | (HISTORY_TWO << 4) | (LITERAL << 3) | (HISTORY_TWO << 2) | (HISTORY_TWO << 1) | (HISTORY_TWO << 0)
