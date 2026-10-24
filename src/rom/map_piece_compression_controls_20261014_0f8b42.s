.setcpu "65816"
.segment "CODE"
.org $8B42
map_control_0f8b42:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
