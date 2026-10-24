.setcpu "65816"
.segment "CODE"
.org $EFE3
control_dcefe3:
    ; backreference count 5, distance 314
    .byte $89, $39
    ; literal count 1; following payload excluded
    .byte $00
