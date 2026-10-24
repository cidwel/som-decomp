.setcpu "65816"
.segment "CODE"
.org $B8C7
map_control_0db8c7:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
