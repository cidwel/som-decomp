.setcpu "65816"
.segment "CODE"
.org $F585
control_dcf585:
    ; backreference count 18, distance 242
    .byte $8F, $F1
    ; literal count 20; following payload excluded
    .byte $13
