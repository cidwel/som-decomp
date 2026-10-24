.setcpu "65816"
.segment "CODE"
.org $EB6C
control_dceb6c:
    ; backreference count 4, distance 512
    .byte $85, $FF
    ; literal count 7; following payload excluded
    .byte $06
