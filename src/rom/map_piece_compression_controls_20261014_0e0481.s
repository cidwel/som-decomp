.setcpu "65816"
.segment "CODE"
.org $0481
map_control_0e0481:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
