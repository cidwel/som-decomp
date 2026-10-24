.setcpu "65816"
.segment "CODE"
.org $EB89
control_dceb89:
    ; backreference count 4, distance 12
    .byte $84, $0B
    ; literal count 32; following payload excluded
    .byte $1F
