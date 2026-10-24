.setcpu "65816"
.segment "CODE"
.org $724D
map_control_0d724d:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
