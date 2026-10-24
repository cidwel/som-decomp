.setcpu "65816"
.segment "CODE"
.org $C3C3
control_c7c3c3:
    ; backreference count 3, distance 68
    .byte $80, $43
    ; backreference count 4, distance 224
    .byte $84, $DF
    ; literal count 14; following payload excluded
    .byte $0D
