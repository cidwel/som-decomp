.setcpu "65816"
.segment "CODE"
.org $ABF6
map_control_0dabf6:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
