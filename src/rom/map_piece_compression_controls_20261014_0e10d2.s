.setcpu "65816"
.segment "CODE"
.org $10D2
map_control_0e10d2:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
