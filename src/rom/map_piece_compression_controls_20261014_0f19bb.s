.setcpu "65816"
.segment "CODE"
.org $19BB
map_control_0f19bb:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
