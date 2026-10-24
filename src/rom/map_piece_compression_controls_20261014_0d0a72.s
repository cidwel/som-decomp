.setcpu "65816"
.segment "CODE"
.org $0A72
map_control_0d0a72:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
