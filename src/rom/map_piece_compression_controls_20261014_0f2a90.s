.setcpu "65816"
.segment "CODE"
.org $2A90
map_control_0f2a90:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
