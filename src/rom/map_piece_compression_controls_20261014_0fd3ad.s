.setcpu "65816"
.segment "CODE"
.org $D3AD
map_control_0fd3ad:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
