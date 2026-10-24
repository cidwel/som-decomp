.setcpu "65816"
.segment "CODE"
.org $2159
map_control_0d2159:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
