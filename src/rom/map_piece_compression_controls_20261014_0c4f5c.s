.setcpu "65816"
.segment "CODE"
.org $4F5C
map_control_0c4f5c:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
