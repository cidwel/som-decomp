.setcpu "65816"
.segment "CODE"
.org $EF27
control_dcef27:
    ; backreference count 3, distance 64
    .byte $80, $3F
    ; literal count 16; following payload excluded
    .byte $0F
