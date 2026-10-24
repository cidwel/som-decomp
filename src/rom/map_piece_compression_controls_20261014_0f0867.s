.setcpu "65816"
.segment "CODE"
.org $0867
map_control_0f0867:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
