.setcpu "65816"
.segment "CODE"
.org $0947
map_control_0f0947:
    .byte $ED ; backreference distance high bits
    .byte $11 ; distance low bit/count
