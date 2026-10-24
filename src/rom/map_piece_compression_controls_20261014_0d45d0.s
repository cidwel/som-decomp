.setcpu "65816"
.segment "CODE"
.org $45D0
map_control_0d45d0:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
