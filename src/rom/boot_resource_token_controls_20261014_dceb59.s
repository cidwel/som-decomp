.setcpu "65816"
.segment "CODE"
.org $EB59
control_dceb59:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 10; following payload excluded
    .byte $09
