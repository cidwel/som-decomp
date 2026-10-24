.setcpu "65816"
.segment "CODE"
.org $D062
map_control_0fd062:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
