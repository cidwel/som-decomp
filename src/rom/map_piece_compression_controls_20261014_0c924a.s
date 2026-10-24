.setcpu "65816"
.segment "CODE"
.org $924A
map_control_0c924a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
