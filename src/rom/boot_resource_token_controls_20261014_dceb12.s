.setcpu "65816"
.segment "CODE"
.org $EB12
control_dceb12:
    ; backreference count 4, distance 960
    .byte $87, $BF
    ; literal count 28; following payload excluded
    .byte $1B
