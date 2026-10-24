.setcpu "65816"
.segment "CODE"
.org $D3F3
map_control_0fd3f3:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
