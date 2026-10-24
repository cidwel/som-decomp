.setcpu "65816"
.segment "CODE"
.org $D074
map_control_0fd074:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
