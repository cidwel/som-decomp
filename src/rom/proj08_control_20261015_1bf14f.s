; MSB-first literal selectors; zero selects two-item history.
.setcpu "65816"
.segment "RODATA"
.org $F14F
HISTORY = 0
LITERAL_BIT_7 = 1 << 7
LITERAL_BIT_6 = 1 << 6
LITERAL_BIT_5 = 1 << 5
LITERAL_BIT_4 = 1 << 4
LITERAL_BIT_3 = 1 << 3
LITERAL_BIT_2 = 1 << 2
LITERAL_BIT_1 = 1 << 1
LITERAL_BIT_0 = 1 << 0
proj08_control_20261015_1bf14f:
    .byte HISTORY
    .byte LITERAL_BIT_7 | LITERAL_BIT_6 | LITERAL_BIT_5 | LITERAL_BIT_3 | LITERAL_BIT_2 | LITERAL_BIT_1 | LITERAL_BIT_0
