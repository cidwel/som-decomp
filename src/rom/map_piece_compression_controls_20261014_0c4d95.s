.setcpu "65816"
.segment "CODE"
.org $4D95
map_control_0c4d95:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
