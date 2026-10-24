.setcpu "65816"
.segment "CODE"
.org $9079
map_control_0c9079:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
