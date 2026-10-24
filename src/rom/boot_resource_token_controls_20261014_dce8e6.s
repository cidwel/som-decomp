.setcpu "65816"
.segment "CODE"
.org $E8E6
control_dce8e6:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 5; following payload excluded
    .byte $04
