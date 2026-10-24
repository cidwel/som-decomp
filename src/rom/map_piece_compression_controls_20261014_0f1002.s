.setcpu "65816"
.segment "CODE"
.org $1002
map_control_0f1002:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
