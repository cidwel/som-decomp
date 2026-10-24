.setcpu "65816"
.segment "CODE"
.org $B3C4
map_control_0fb3c4:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
