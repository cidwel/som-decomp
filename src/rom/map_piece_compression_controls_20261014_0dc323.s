.setcpu "65816"
.segment "CODE"
.org $C323
map_control_0dc323:
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count
