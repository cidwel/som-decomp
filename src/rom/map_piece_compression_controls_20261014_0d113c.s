.setcpu "65816"
.segment "CODE"
.org $113C
map_control_0d113c:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
