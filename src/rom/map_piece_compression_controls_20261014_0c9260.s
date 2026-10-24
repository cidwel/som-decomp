.setcpu "65816"
.segment "CODE"
.org $9260
map_control_0c9260:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
