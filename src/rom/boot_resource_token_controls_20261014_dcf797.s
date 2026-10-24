.setcpu "65816"
.segment "CODE"
.org $F797
control_dcf797:
    ; backreference count 130, distance 194
    .byte $FF, $C1
    ; backreference count 64, distance 256
    .byte $BD, $FF
    ; literal count 29; following payload excluded
    .byte $1C
