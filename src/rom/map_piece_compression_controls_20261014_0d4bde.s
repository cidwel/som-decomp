.setcpu "65816"
.segment "CODE"
.org $4BDE
map_control_0d4bde:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
