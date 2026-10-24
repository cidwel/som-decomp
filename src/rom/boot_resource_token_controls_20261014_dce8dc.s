.setcpu "65816"
.segment "CODE"
.org $E8DC
control_dce8dc:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 7; following payload excluded
    .byte $06
