.setcpu "65816"
.segment "CODE"
.org $F41C
control_dcf41c:
    ; backreference count 4, distance 52
    .byte $81, $33
    ; literal count 12; following payload excluded
    .byte $0B
