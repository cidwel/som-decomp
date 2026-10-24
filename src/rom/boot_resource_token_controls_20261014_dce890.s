.setcpu "65816"
.segment "CODE"
.org $E890
control_dce890:
    ; backreference count 3, distance 498
    .byte $81, $F1
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 5; following payload excluded
    .byte $04
