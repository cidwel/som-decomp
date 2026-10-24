.setcpu "65816"
.segment "CODE"
.org $9099
map_control_0c9099:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
