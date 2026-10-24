; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F3E5
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf3e5:
    .byte (LITERAL << 7) | (LITERAL << 6) | (LITERAL << 5) | (LITERAL << 4) | (LITERAL << 3) | (LITERAL << 2) | (LITERAL << 1) | (HISTORY_TWO << 0)
