.setcpu "65816"
.segment "CODE"
.org $D09B
map_control_0fd09b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
