.setcpu "65816"
.segment "CODE"
.org $9D5D
map_control_0f9d5d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
