.setcpu "65816"
.segment "CODE"
.org $2A95
map_control_0d2a95:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
