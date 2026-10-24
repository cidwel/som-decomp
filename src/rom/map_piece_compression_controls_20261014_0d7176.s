.setcpu "65816"
.segment "CODE"
.org $7176
map_control_0d7176:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
