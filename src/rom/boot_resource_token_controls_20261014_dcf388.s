.setcpu "65816"
.segment "CODE"
.org $F388
control_dcf388:
    ; backreference count 96, distance 127
    .byte $DD, $7E
    ; literal count 17; following payload excluded
    .byte $10
