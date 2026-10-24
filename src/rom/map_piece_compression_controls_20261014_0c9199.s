.setcpu "65816"
.segment "CODE"
.org $9199
map_control_0c9199:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
