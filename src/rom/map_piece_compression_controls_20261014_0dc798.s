.setcpu "65816"
.segment "CODE"
.org $C798
map_control_0dc798:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
