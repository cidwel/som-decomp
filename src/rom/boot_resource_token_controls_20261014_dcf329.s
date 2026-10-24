.setcpu "65816"
.segment "CODE"
.org $F329
control_dcf329:
    ; backreference count 21, distance 60
    .byte $92, $3B
    ; literal count 9; following payload excluded
    .byte $08
