.setcpu "65816"
.segment "CODE"
.org $7F12
map_control_0f7f12:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
