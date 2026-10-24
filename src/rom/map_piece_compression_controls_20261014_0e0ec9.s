.setcpu "65816"
.segment "CODE"
.org $0EC9
map_control_0e0ec9:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
