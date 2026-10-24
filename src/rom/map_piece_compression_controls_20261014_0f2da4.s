.setcpu "65816"
.segment "CODE"
.org $2DA4
map_control_0f2da4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
