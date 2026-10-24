.setcpu "65816"
.segment "CODE"
.org $81C5
map_control_0c81c5:
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
