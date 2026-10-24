.setcpu "65816"
.segment "CODE"
.org $EDAC
control_dcedac:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 17; following payload excluded
    .byte $10
