.setcpu "65816"
.segment "CODE"
.org $0A36
map_control_0f0a36:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
