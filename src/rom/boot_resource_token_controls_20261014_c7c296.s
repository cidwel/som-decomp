.setcpu "65816"
.segment "CODE"
.org $C296
control_c7c296:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; backreference count 3, distance 152
    .byte $80, $97
    ; literal count 1; following payload excluded
    .byte $00
