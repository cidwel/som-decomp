.setcpu "65816"
.segment "CODE"
.org $2139
map_control_0f2139:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
