.setcpu "65816"
.segment "CODE"
.org $29AD
map_control_0f29ad:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
