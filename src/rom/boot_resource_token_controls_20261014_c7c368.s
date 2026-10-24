.setcpu "65816"
.segment "CODE"
.org $C368
control_c7c368:
    ; backreference count 3, distance 448
    .byte $81, $BF
    ; literal count 5; following payload excluded
    .byte $04
