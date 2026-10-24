.setcpu "65816"
.segment "CODE"
.org $543A
map_control_0f543a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
