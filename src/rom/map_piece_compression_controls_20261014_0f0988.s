.setcpu "65816"
.segment "CODE"
.org $0988
map_control_0f0988:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
