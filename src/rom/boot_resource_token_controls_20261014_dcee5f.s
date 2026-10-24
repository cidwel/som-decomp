.setcpu "65816"
.segment "CODE"
.org $EE5F
control_dcee5f:
    ; backreference count 4, distance 64
    .byte $84, $3F
    ; literal count 1; following payload excluded
    .byte $00
