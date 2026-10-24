.setcpu "65816"
.segment "CODE"
.org $1E1B
map_control_0f1e1b:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
