.setcpu "65816"
.segment "CODE"
.org $E806
control_dce806:
    ; backreference count 6, distance 1
    .byte $8C, $00
    ; literal count 9; following payload excluded
    .byte $08
