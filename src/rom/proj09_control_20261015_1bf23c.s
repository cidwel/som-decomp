; MSB-first item modes: literal input or two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F23C
LITERAL = 1
HISTORY_TWO = 0
proj09_control_20261015_1bf23c:
    .byte (LITERAL << 7) | (LITERAL << 6) | (LITERAL << 5) | (LITERAL << 4) | (HISTORY_TWO << 3) | (LITERAL << 2) | (LITERAL << 1) | (LITERAL << 0)
