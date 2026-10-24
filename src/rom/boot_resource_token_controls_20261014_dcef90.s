.setcpu "65816"
.segment "CODE"
.org $EF90
control_dcef90:
    ; backreference count 4, distance 100
    .byte $84, $63
    ; literal count 15; following payload excluded
    .byte $0E
