.setcpu "65816"
.segment "CODE"
.org $7155
map_control_0d7155:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
