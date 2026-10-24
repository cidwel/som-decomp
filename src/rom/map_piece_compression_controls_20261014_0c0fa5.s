.setcpu "65816"
.segment "CODE"
.org $0FA5
map_control_0c0fa5:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
