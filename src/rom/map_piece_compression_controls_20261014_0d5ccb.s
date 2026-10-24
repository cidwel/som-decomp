.setcpu "65816"
.segment "CODE"
.org $5CCB
map_control_0d5ccb:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
