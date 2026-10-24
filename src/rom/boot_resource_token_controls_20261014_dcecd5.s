.setcpu "65816"
.segment "CODE"
.org $ECD5
control_dcecd5:
    ; backreference count 3, distance 84
    .byte $80, $53
    ; literal count 1; following payload excluded
    .byte $00
