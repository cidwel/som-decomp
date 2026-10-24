.setcpu "65816"
.segment "CODE"
.org $EF6A
control_dcef6a:
    ; backreference count 8, distance 192
    .byte $94, $BF
    ; literal count 5; following payload excluded
    .byte $04
