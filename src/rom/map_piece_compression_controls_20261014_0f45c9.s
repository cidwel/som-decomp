.setcpu "65816"
.segment "CODE"
.org $45C9
map_control_0f45c9:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
