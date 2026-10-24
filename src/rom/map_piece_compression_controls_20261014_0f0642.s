.setcpu "65816"
.segment "CODE"
.org $0642
map_control_0f0642:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
