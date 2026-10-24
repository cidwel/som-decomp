.setcpu "65816"
.segment "CODE"
.org $F770
control_dcf770:
    ; backreference count 130, distance 178
    .byte $FF, $B1
    ; backreference count 78, distance 1
    .byte $CB, $00
    ; literal count 1; following payload excluded
    .byte $00
