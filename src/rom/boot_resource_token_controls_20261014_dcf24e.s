.setcpu "65816"
.segment "CODE"
.org $F24E
control_dcf24e:
    ; backreference count 4, distance 1
    .byte $81, $00
    ; literal count 9; following payload excluded
    .byte $08
