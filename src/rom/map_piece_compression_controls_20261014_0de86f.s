.setcpu "65816"
.segment "CODE"
.org $E86F
map_control_0de86f:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
