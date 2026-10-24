.setcpu "65816"
.segment "CODE"
.org $ED38
control_dced38:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 17; following payload excluded
    .byte $10
