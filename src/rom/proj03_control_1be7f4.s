; Bits 7..0 select literal (1) or two-item history (0).
.setcpu "65816"
.segment "RODATA"
HISTORY_ONLY = 0
LITERAL_0 = (1 << 0)
LITERAL_1 = (1 << 1)
LITERAL_2 = (1 << 2)
LITERAL_3 = (1 << 3)
LITERAL_4 = (1 << 4)
LITERAL_5 = (1 << 5)
LITERAL_6 = (1 << 6)
LITERAL_7 = (1 << 7)
.org $E7F4
proj03_control_1be7f4:
    .byte (LITERAL_3 | LITERAL_1)
