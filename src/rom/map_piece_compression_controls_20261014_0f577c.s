.setcpu "65816"
.segment "CODE"
.org $577C
map_control_0f577c:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
