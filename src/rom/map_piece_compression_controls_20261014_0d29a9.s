.setcpu "65816"
.segment "CODE"
.org $29A9
map_control_0d29a9:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
