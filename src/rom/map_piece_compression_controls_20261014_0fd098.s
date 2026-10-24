.setcpu "65816"
.segment "CODE"
.org $D098
map_control_0fd098:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
