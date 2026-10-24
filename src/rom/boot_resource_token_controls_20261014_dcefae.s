.setcpu "65816"
.segment "CODE"
.org $EFAE
control_dcefae:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 23; following payload excluded
    .byte $16
