; Bits select literal (1) or two-item history (0), MSB first.
.setcpu "65816"
.segment "RODATA"
.org $F6CD
HISTORY = 0
LITERAL_0 = $80
LITERAL_1 = $40
LITERAL_2 = $20
LITERAL_3 = $10
LITERAL_4 = $08
LITERAL_5 = $04
LITERAL_6 = $02
LITERAL_7 = $01
proj0b_control_20261015_1bf6cd:
    .byte (LITERAL_4 | LITERAL_5 | LITERAL_6)
.assert * - proj0b_control_20261015_1bf6cd = 1, error, "Exact mask span"
