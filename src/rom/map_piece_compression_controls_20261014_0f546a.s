.setcpu "65816"
.segment "CODE"
.org $546A
map_control_0f546a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
