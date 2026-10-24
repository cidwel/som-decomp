.setcpu "65816"
.segment "CODE"
.org $04BC
map_control_0e04bc:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
