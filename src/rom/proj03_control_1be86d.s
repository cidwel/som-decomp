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
.org $E86D
proj03_control_1be86d:
    .byte (LITERAL_7 | LITERAL_6 | LITERAL_5 | LITERAL_3 | LITERAL_2 | LITERAL_1 | LITERAL_0)
