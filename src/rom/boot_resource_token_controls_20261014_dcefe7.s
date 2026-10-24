.setcpu "65816"
.segment "CODE"
.org $EFE7
control_dcefe7:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 19; following payload excluded
    .byte $12
