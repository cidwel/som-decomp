.setcpu "65816"
.segment "CODE"
.org $E901
control_dce901:
    ; backreference count 7, distance 15
    .byte $90, $0E
    ; literal count 5; following payload excluded
    .byte $04
