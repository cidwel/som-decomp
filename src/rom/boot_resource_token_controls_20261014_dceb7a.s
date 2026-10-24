.setcpu "65816"
.segment "CODE"
.org $EB7A
control_dceb7a:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 1; following payload excluded
    .byte $00
