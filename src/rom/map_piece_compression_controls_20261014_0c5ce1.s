.setcpu "65816"
.segment "CODE"
.org $5CE1
map_control_0c5ce1:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
