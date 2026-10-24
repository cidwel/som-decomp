.setcpu "65816"
.segment "CODE"
.org $C9E5
map_control_0ec9e5:
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
