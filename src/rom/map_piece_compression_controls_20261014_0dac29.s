.setcpu "65816"
.segment "CODE"
.org $AC29
map_control_0dac29:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
