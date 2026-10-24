; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F32C
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf32c:
    .byte (HISTORY_TWO << 7) | (HISTORY_TWO << 6) | (LITERAL << 5) | (LITERAL << 4) | (LITERAL << 3) | (LITERAL << 2) | (LITERAL << 1) | (LITERAL << 0)
