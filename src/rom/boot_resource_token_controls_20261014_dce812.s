.setcpu "65816"
.segment "CODE"
.org $E812
control_dce812:
    ; backreference count 7, distance 15
    .byte $90, $0E
    ; literal count 9; following payload excluded
    .byte $08
