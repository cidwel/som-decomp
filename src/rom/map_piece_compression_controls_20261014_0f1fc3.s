.setcpu "65816"
.segment "CODE"
.org $1FC3
map_control_0f1fc3:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
