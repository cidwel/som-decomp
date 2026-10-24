.setcpu "65816"
.segment "CODE"
.org $3185
map_control_0f3185:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
