.setcpu "65816"
.segment "CODE"
.org $33C1
map_control_0d33c1:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
