.setcpu "65816"
.segment "CODE"
.org $EF61
control_dcef61:
    ; backreference count 5, distance 36
    .byte $88, $23
    ; backreference count 32, distance 192
    .byte $F4, $BF
    ; literal count 4; following payload excluded
    .byte $03
