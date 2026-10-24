.setcpu "65816"
.segment "CODE"
.org $7155
map_control_0f7155:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
