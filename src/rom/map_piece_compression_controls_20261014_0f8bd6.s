.setcpu "65816"
.segment "CODE"
.org $8BD6
map_control_0f8bd6:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
