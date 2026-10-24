.setcpu "65816"
.segment "CODE"
.org $5243
map_control_0d5243:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
