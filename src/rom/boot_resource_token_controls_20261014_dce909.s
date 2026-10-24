.setcpu "65816"
.segment "CODE"
.org $E909
control_dce909:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 23; following payload excluded
    .byte $16
