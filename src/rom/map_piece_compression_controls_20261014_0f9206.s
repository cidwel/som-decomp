.setcpu "65816"
.segment "CODE"
.org $9206
map_control_0f9206:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
