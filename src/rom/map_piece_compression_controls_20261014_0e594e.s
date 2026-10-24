.setcpu "65816"
.segment "CODE"
.org $594E
map_control_0e594e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
