.setcpu "65816"
.segment "CODE"
.org $EFFD
control_dceffd:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 1; following payload excluded
    .byte $00
