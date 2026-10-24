.setcpu "65816"
.segment "CODE"
.org $D075
map_control_0ed075:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
