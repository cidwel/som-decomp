.setcpu "65816"
.segment "CODE"
.org $0949
map_control_0d0949:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
