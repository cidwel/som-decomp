.setcpu "65816"
.segment "CODE"
.org $2A50
map_control_0d2a50:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
