.setcpu "65816"
.segment "CODE"
.org $EC47
map_control_0eec47:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
