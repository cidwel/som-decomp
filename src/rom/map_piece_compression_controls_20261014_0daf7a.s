.setcpu "65816"
.segment "CODE"
.org $AF7A
map_control_0daf7a:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
