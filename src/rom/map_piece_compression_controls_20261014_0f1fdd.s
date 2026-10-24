.setcpu "65816"
.segment "CODE"
.org $1FDD
map_control_0f1fdd:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
