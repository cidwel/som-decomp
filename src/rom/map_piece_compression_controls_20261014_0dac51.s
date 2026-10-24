.setcpu "65816"
.segment "CODE"
.org $AC51
map_control_0dac51:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
