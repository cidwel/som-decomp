.setcpu "65816"
.segment "CODE"
.org $E6D5
map_control_0fe6d5:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
