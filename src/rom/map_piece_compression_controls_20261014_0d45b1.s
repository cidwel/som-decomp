.setcpu "65816"
.segment "CODE"
.org $45B1
map_control_0d45b1:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
